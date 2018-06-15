# avr-bit-funcs
## Bit manipulation functions
Fast bit manipulation macro functions for controlling Arduino or AVR microcontroller pins.

Only tested on ATmega2560.

## Examples
**Blink**
    
    #include "Arduino.h"
    #include "avr_bit_funcs.h"
    
    const uint16_t LED[2] = {PB, 7};
    
    void setup() {
        SET_OUTPUT(LED);
    }
    
    void loop() {
        SET_HIGH(LED);
        delay(200);
        SET_LOW(LED);
        delay(200);
    }

**Blink array**

    #include "Arduino.h"
    #include "avr_bit_funcs.h"

    #define NUM_LEDS

    const uint16_t LEDS[NUM_LEDS][2] = {
        {PB, 4},
        {PB, 5}
    };
    
    void setup() {
        for (int i = 0; i < NUM_LEDS; ++i) {
            SET_OUTPUT(LEDS[i]);
        }
    }
    
    void loop() {
        for (int i = 0; i < NUM_LEDS; ++i) {
            SET_HIGH(LEDS[i]);
        }
        delay(200);
        for (int i = 0; i < NUM_LEDS; ++i) {
            SET_LOW(LEDS[i]);
        }
        delay(200);
    }
