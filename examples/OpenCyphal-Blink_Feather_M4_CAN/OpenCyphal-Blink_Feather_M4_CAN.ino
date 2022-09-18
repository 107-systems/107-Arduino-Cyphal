/*
 * This example creates a OpenCyphal node. The builtin LED can be switched on and off using OpenCyphal.
 * It also shows periodic transmission of a OpenCyphal heartbeat message via CAN.
 *
 * switch built in LED on with
 *   yakut -i 'CAN(can.media.socketcan.SocketCANMedia("can0",8),59)' pub 1620.uavcan.primitive.scalar.Bit.1.0 'value: true'
 *
 * switch built in LED off with
 *   yakut -i 'CAN(can.media.socketcan.SocketCANMedia("can0",8),59)' pub 1620.uavcan.primitive.scalar.Bit.1.0 'value: false'
 *
 * Hardware:
 *   - Adafruit Feather M4 CAN Express
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <CAN.h>

#include <107-Arduino-Cyphal.h>
#if defined(ARDUINO_EDGE_CONTROL)
#  include <Arduino_EdgeControl.h>
#endif

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace uavcan::node;
using namespace uavcan::primitive::scalar;

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static CanardPortID const BIT_PORT_ID   = 1620U;

#if defined(ESP32)
static int const LED_BUILTIN = 2;
#endif

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const &);
void onBit_1_0_Received (CanardRxTransfer const &, Node &);
bool transmitCanFrame(CanardFrame const & frame);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

Node node_hdl(transmitCanFrame);

Heartbeat_1_0<> hb;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }

  /* Setup LED and initialize */
#if defined(ARDUINO_EDGE_CONTROL)
  Power.on(PWR_3V3);
  Power.on(PWR_VBAT);
  if (!Expander.begin())
  {
    Serial.println("Arduino Edge Control - Expander.begin() failed");
    for(;;) { }
    Expander.pinMode(EXP_LED1, OUTPUT);
  }
#else
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
#endif

  pinMode(PIN_CAN_STANDBY, OUTPUT);
  digitalWrite(PIN_CAN_STANDBY, false); // turn off STANDBY
  pinMode(PIN_CAN_BOOSTEN, OUTPUT);
  digitalWrite(PIN_CAN_BOOSTEN, true); // turn on booster
  
 /* start the CAN bus at 250 kbps */
  if (!CAN.begin(250E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
  // register the receive callback
  CAN.onReceive(onReceive);

  /* Configure initial heartbeat */
  hb.data.uptime = 0;
  hb = Heartbeat_1_0<>::Health::NOMINAL;
  hb = Heartbeat_1_0<>::Mode::INITIALIZATION;
  hb.data.vendor_specific_status_code = 0;

  /* Subscribe to the reception of Bit message. */
  node_hdl.subscribe<Bit_1_0<BIT_PORT_ID>>(onBit_1_0_Received);
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  node_hdl.spinSome();

  /* Update the heartbeat object */
  hb.data.uptime = millis() / 1000;
  hb = Heartbeat_1_0<>::Mode::OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    node_hdl.publish(hb);
    prev = now;
  }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void onReceive(int packetSize) {
  static CanardFrame frame;
  static char payload[8];
  // received a packet
  Serial.print("Received ");

  if (CAN.packetExtended()) {
    Serial.print("extended ");
  }

  if (CAN.packetRtr()) {
    // Remote transmission request, packet contains no data
    Serial.print("RTR ");
  }

  Serial.print("packet with id 0x");
  Serial.print(CAN.packetId(), HEX);
  frame.extended_can_id=CAN.packetId();

  if (CAN.packetRtr()) {
    Serial.print(" and requested length ");
    Serial.println(CAN.packetDlc());
  } else {
    Serial.print(" and length ");
    Serial.println(packetSize);
    frame.payload_size=packetSize;

    // only print packet data for non-RTR packets
    uint8_t i=0;
    while (CAN.available()) {
      payload[i]=(char)CAN.read();
      Serial.print(payload[i], HEX);
      if(i<7) i++;
    }
    frame.payload=&payload;
    Serial.println();

    node_hdl.onCanFrameReceived(frame, micros());
  }
}

bool transmitCanFrame(CanardFrame const & frame)
{
  CAN.beginExtendedPacket(frame.extended_can_id);
  CAN.write((const uint8_t *)frame.payload, frame.payload_size);
  CAN.endPacket();
  return true;
}

void onBit_1_0_Received(CanardRxTransfer const & transfer, Node & /* node_hdl */)
{
  Bit_1_0<BIT_PORT_ID> const uavcan_led = Bit_1_0<BIT_PORT_ID>::deserialize(transfer);

  if(uavcan_led.data.value)
  {
#if defined(ARDUINO_EDGE_CONTROL)
    Expander.digitalWrite(EXP_LED1, LOW);
#else
    digitalWrite(LED_BUILTIN, HIGH);
#endif
    Serial.println("Received Bit: true");
  }
  else
  {
#if defined(ARDUINO_EDGE_CONTROL)
    Expander.digitalWrite(EXP_LED1, HIGH);
#else
    digitalWrite(LED_BUILTIN, LOW);
#endif
    Serial.println("Received Bit: false");
  }
}
