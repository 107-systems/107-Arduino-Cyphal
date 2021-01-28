/*
 * This example shows reception of a UAVCAN heartbeat message via CAN.
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
void    onSourceTs_0_1_Received(CanardTransfer const &, ArduinoUAVCAN &);
void    onStatus_0_2_Received(CanardTransfer const &, ArduinoUAVCAN &);
void    onParameters_0_2_Received(CanardTransfer const &, ArduinoUAVCAN & );

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       micros,
                       onReceiveBufferFull,
                       nullptr);

ArduinoUAVCAN uavcan(13, nullptr);

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

  /* Subscribe to the reception of BMS message types. */
  uavcan.subscribe<SourceTs_0_1>(onSourceTs_0_1_Received);
  uavcan.subscribe<Status_0_2>(onStatus_0_2_Received);
  uavcan.subscribe<Parameters_0_2>(onParameters_0_2_Received);
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


void onSourceTs_0_1_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  SourceTs_0_1 const source = SourceTs_0_1::deserialize(transfer);

  Serial.print("SourceTs->\tTimestamp: ");
  Serial.print((double)source.data.timestamp.microsecond/1000);
  Serial.print(", Energy: ");
  Serial.print(source.data.value.energy.joule);
  Serial.print(", Full Energy: ");
  Serial.print(source.data.value.full_energy.joule);
  Serial.print(", Current: ");
  Serial.print(source.data.value.power.current.ampere);
  Serial.print(", Total Voltage: ");
  Serial.print(source.data.value.power.voltage.volt);
  Serial.println();
}

void onStatus_0_2_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */){
  Status_0_2 const stat = Status_0_2::deserialize(transfer);

  Serial.print("Status->\tAvailable Charge: ");
  Serial.print(stat.data.available_charge.coulomb);
  Serial.print(", Cell Voltages: ");
  for(int i = 0; i < stat.data.cell_voltages.count; i++){
    Serial.print(stat.data.cell_voltages.elements[i]);
    Serial.print(", ");
  }
  Serial.print("Temperature Min: ");
  Serial.print(stat.data.temperature_min_max[0].kelvin);
  Serial.print(", Temperature Max: ");
  Serial.print(stat.data.temperature_min_max[1].kelvin);
  Serial.println();
}


void onParameters_0_2_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */){
  Parameters_0_2 const params = Parameters_0_2::deserialize(transfer);

  Serial.print("Parameters->\tUnique ID: ");
  Serial.print(params.data.unique_id);
  Serial.print(", Technology: ");
  Serial.print(params.data.technology.value);
  Serial.print(", Min Cell Voltage: ");
  Serial.print(params.data.design_cell_voltage_min_max[0].volt);
  Serial.print(", Max Cell Voltage: ");
  Serial.print(params.data.design_cell_voltage_min_max[1].volt);
  Serial.print(", Design Capacity: ");
  Serial.print(params.data.design_capacity.coulomb);
  Serial.print(", Discharge Current: ");
  Serial.print(params.data.discharge_current.ampere);
  Serial.print(", Charge Current: ");
  Serial.print(params.data.charge_current.ampere);
  Serial.print(", Fast Discharge Current: ");
  Serial.print(params.data.charge_current_fast.ampere);
  Serial.print(", Fast Charge Current: ");
  Serial.print(params.data.charge_current_fast.ampere);
  Serial.print(", Charge Termination Threshold: ");
  Serial.print(params.data.charge_termination_treshold.ampere);
  Serial.print(", Charge Voltage: ");
  Serial.print(params.data.charge_voltage.volt);
  Serial.print(", State of Health (%): ");
  Serial.print(params.data.state_of_health_pct);
  Serial.println();
}
