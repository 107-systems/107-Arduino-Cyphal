/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <ArduinoOrel20.h>
#include <ArduinoO1Heap.h>
#include <ArduinoCanard.h>

/**************************************************************************************
 * FUNCTION DECLARATIONS
 **************************************************************************************/

void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
void   o1heap_free    (CanardInstance * const ins, void * const pointer);

/**************************************************************************************
 * GLOBAL CONSTANTS
 **************************************************************************************/

static uint8_t const THIS_NODE_ID = 1;

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoO1Heap o1heap;
ArduinoCanard canard(THIS_NODE_ID, o1heap_allocate, o1heap_free);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{

}

void loop()
{

}

/**************************************************************************************
 * FUNCTION DEFINITIONS
 **************************************************************************************/

void * o1heap_allocate(CanardInstance * const ins, size_t const amount)
{
  (void)ins;
  return o1heap.allocate(amount);
}

void o1heap_free(CanardInstance * const ins, void * const pointer)
{
  (void)ins;
  o1heap.free(pointer);
}
