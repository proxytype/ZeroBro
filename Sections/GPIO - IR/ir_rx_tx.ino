
#define RAW_BUFFER_LENGTH 750
#include <IRremote.h>

const byte IR_RECEIVE_PIN = 4;
const byte IR_TRASMITTER_PIN = 3;

IRrecv irrecv(IR_RECEIVE_PIN);
IRsend irsend(IR_TRASMITTER_PIN);

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn();
} 

void dump() {

Serial.println(); // blank line between entries
Serial.println(); // 2 blank lines between entries
irrecv.printIRResultShort(&Serial);
// Check if the buffer overflowed
if (irrecv.decodedIRData.flags & IRDATA_FLAGS_WAS_OVERFLOW) {
      Serial.println("Try to increase the RAW_BUFFER_LENGTH");
      // see also https://github.com/Arduino-IRremote/Arduino-IRremote#compile-options--macros-for-this-library
} else {

  if (irrecv.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
  }

  Serial.println();
  irrecv.printIRSendUsage(&Serial);
  
  Serial.println();
  Serial.println(F("Raw result in internal ticks (50 us) - with leading gap"));
  
  irrecv.printIRResultRawFormatted(&Serial, false); // Output the results in RAW format
            
  Serial.println(F("Raw result in microseconds - with leading gap"));
            
  irrecv.printIRResultRawFormatted(&Serial, true);  // Output the results in RAW format
        
  Serial.println();                               // blank line between entries
  Serial.print(F("Result as internal 8bit ticks (50 us) array - compensated with MARK_EXCESS_MICROS="));
  Serial.println(MARK_EXCESS_MICROS);
            
  irrecv.compensateAndPrintIRResultAsCArray(&Serial, false); // Output the results as uint8_t source code array of ticks
            
  Serial.print(F("Result as microseconds array - compensated with MARK_EXCESS_MICROS="));
  Serial.println(MARK_EXCESS_MICROS);
            
  irrecv.compensateAndPrintIRResultAsCArray(&Serial, true); // Output the results as uint16_t source code array of micros           
  irrecv.printIRResultAsCVariables(&Serial);  // Output address and data as source code variables            
  irrecv.compensateAndPrintIRResultAsPronto(&Serial);
        
 }
}

void loop()
{
  if (irrecv.decode())
  {
    //38Khz
    irsend.sendRaw(irrecv.decodedIRData.rawDataPtr->rawbuf, irrecv.decodedIRData.rawDataPtr->rawlen , 38); 
    dump();
    irrecv.resume(); 
  }
} 

