# avr-bit-funcs
## Bit manipulation functions
Fast bit manipulation functions for controlling Arduino or AVR microcontroller pins.

## Speed
Pulsing a pin high and low using `digitalWrite` gives a pulse width of ~6us. Using `setHigh` and `setLow` to create a pulse gives a width of 125ns (or just two clock cycles) on an 8MHz device.

## Examples
**Blink**
    
    #include "Arduino.h"
    #include "avr_bit_funcs.h"
    
    volatile uint8_t *LED_DDR = &DDRB;
    volatile uint8_t *LED_PIN = &PINB;
    volatile uint8_t *LED_PORT = &PORTB;
    uint8_t LED = PB7;
    
    void setup() {
        setOutput(LED);
    }
    
    void loop() {
        setHigh(LED);
        delay(200);
        setLow(LED);
        delay(200);
    }

**Blink array**

    #include "avr_bit_funcs.h"
    #include "Arduino.h"
    
    #define NUM_OUTPUTS 2
    
    volatile uint8_t *OUTPUTS_DDR[NUM_OUTPUTS] = {&DDRB, &DDRB};
    volatile uint8_t *OUTPUTS_PIN[NUM_OUTPUTS] = {&PINB, &PINB};
    volatile uint8_t *OUTPUTS_PORT[NUM_OUTPUTS] = {&PORTB, &PORTB};
    uint8_t OUTPUTS[NUM_OUTPUTS] = {PB4, PB5};
    
    void setup() {
        for (uint8_t i=0; i<NUM_OUTPUTS; ++i) {
            arrSetOutput(OUTPUTS, i);
        }
    }
    
    void loop() {
        for (uint8_t i=0; i<NUM_OUTPUTS; ++i) {
            arrSetHigh(OUTPUTS, i);
        }
        delay(200);
    
        for (uint8_t i=0; i<NUM_OUTPUTS; ++i) {
            arrSetLow(OUTPUTS, i);
        }
        delay(200);
    }
