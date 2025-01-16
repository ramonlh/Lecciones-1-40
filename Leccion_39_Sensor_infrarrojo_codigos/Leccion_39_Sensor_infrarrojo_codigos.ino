//  This file is part of Arduino-IRremote https://github.com/Arduino-IRremote/Arduino-IRremote.
 
#include <Arduino.h>

#define LED_BUILTIN              2
#define IR_RECEIVE_PIN          14  // D15

/* Specify which protocol(s) should be used for decoding.
 * If no protocol is defined, all protocols (except Bang&Olufsen) are active.
 * This must be done before the #include <IRremote.hpp>  */

//#define DECODE_DENON        // Includes Sharp
//#define DECODE_JVC
//#define DECODE_KASEIKYO
//#define DECODE_PANASONIC    // alias for DECODE_KASEIKYO
//#define DECODE_LG
#define DECODE_NEC          // Includes Apple and Onkyo. To enable all protocols , just comment/disable this line.
//#define DECODE_SAMSUNG
//#define DECODE_SONY
//#define DECODE_RC5
//#define DECODE_RC6

//#define DECODE_BOSEWAVE
//#define DECODE_LEGO_PF
//#define DECODE_MAGIQUEST
//#define DECODE_WHYNTER
//#define DECODE_FAST

//#define DECODE_DISTANCE_WIDTH // Universal decoder for pulse distance width protocols
//#define DECODE_HASH         // special decoder for all protocols

//#define DECODE_BEO          // This protocol must always be enabled manually, i.e. it is NOT enabled if no protocol is defined. It prevents decoding of SONY!

//#define DEBUG               // Activate this for lots of lovely debug output from the decoders.

//#define RAW_BUFFER_LENGTH  750 // For air condition remotes it requires 750. Default is 200.

// This include defines the actual pin number for pins like IR_RECEIVE_PIN, IR_SEND_PIN for many different boards and architectures
#include <IRremote.hpp> // include the library

void setup() {
    Serial.begin(115200);

    IrReceiver.begin(IR_RECEIVE_PIN, false);

    Serial.print("Preparado para protocolo: ");    printActiveIRProtocols(&Serial);
    Serial.print("en el pin ");    Serial.println(IR_RECEIVE_PIN);
}

void loop() {
    if (IrReceiver.decode()) 
      {
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
          Serial.print(".");
            //Serial.println("Received noise or an unknown ");
            // We have an unknown protocol here, print extended info
           // IrReceiver.printIRResultRawFormatted(&Serial, true);
           // IrReceiver.resume(); // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
          } 
        else 
          {
            Serial.println("XXXXXXXXXXXXXXX");
            IrReceiver.resume(); // Early enable receiving of the next IR frame
            IrReceiver.printIRResultShort(&Serial);
            IrReceiver.printIRSendUsage(&Serial);
          }

        if (IrReceiver.decodedIRData.command == 0x10) {
            // do something
          } 
        else if (IrReceiver.decodedIRData.command == 0x11) {
            // do something else
          }
    }
  delay(100);
}
