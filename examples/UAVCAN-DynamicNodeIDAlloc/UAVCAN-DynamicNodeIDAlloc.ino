/*
 * This example implements a basic Node ID allocator. On any given bus, there could be 0, 1, 3 or 5
 * allocators. The allocatee will anonymously send a unique hardware ID (think MAC address), which will 
 * be received by the allocator. The allocator will then associate the unique ID with an available Node ID
 * and store the pair in a lookup table. The ID, along with the origional unique hardware ID will be sent
 * back to the allocatee using the same message type
 *
 * Hardware:
 *   - Arduino MKR family board, e.g. MKR VIDOR 4000
 *   - Arduino MKR CAN shield
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <SPI.h>

#include <ArduinoUAVCAN.h>
#include <ArduinoMCP2515.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int const MKRCAN_MCP2515_CS_PIN  = 3;
static int const MKRCAN_MCP2515_INT_PIN = 7;

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void    spi_select             ();
void    spi_deselect           ();
uint8_t spi_transfer           (uint8_t const);
void    onExternalEvent        ();
void    onReceiveBufferFull    (CanardFrame const &);
void    onAllocRecv(CanardTransfer const &, ArduinoUAVCAN &);
bool    transmitCanFrame(CanardFrame const &);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       micros,
                       onReceiveBufferFull,
                       nullptr);

ArduinoUAVCAN uavcan(13, transmitCanFrame);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }

  /* Setup SPI access */
  SPI.begin();
  pinMode(MKRCAN_MCP2515_CS_PIN, OUTPUT);
  digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);

  /* Attach interrupt handler to register MCP2515 signaled by taking INT low */
  pinMode(MKRCAN_MCP2515_INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), onExternalEvent, FALLING);

  /* Initialize MCP2515 */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS);
  mcp2515.setNormalMode();

  /* Subscribe to the reception of NodeID message. */
  uavcan.subscribe<NodeIDAllocationData>(NodeIDAllocationData);
}

void loop()
{

}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void spi_select()
{
  digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW);
}

void spi_deselect()
{
  digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);
}

uint8_t spi_transfer(uint8_t const data)
{
  return SPI.transfer(data);
}

void onExternalEvent()
{
  mcp2515.onExternalEventHandler();
}

void onReceiveBufferFull(CanardFrame const & frame)
{
  uavcan.onCanFrameReceived(frame);
}

void onAllocRecv(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  
  // Get data struct
  NodeIDAllocationData const al = NodeIDAllocationData::deserialize(transfer);

  // Get unique 16 byte id (unique to hardware)
  for (int i=0; i<16; ++i) {
      serial.print(al.data.unique_id[i], HEX);
  }
  Serial.println();


  // Determine Node ID & store in LUT
  al.data.node_id = 10; // temporary, for testing

  // Populate message with nodeID & return to sender
  uavcan.publish(al);
  while(uavcan.transmitCanFrame()) { }

}

bool transmitCanFrame(CanardFrame const & frame)
{
  return mcp2515.transmit(frame);
}
