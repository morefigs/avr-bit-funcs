# AVR bit funcs
## Bit manipulation functions

### Usage
    
    #include "avr_bit_funcs.h"    
    
    void setup() {
        volatile uint8_t *LED = &DDRB;
        volatile uint8_t *LED = &PORTB;
        volatile uint8_t *LED = &PINB;
        uint8_t LED = PB7;
        
        setOutput(LED);        
    }
    
    void loop() {
        setHigh(LED);
        setLow(LED);
    }
