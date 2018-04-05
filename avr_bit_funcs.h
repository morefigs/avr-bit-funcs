#ifndef AVR_BIT_FUNCS
#define AVR_BIT_FUNCS

// get byte value
#define _b(bit)                         (1 << (bit))

// use the following variable naming convention for these macros
//volatile uint8_t *FOO = &DDRB;
//volatile uint8_t *FOO = &PORTB;
//volatile uint8_t *FOO = &PINB;
//uint8_t FOO = PB7;
#define setOutput(bit)                  {*bit ## _DDR |= _b(bit);}
#define setInput(bit)                   {*bit ## _DDR &= ~_b(bit);}
#define enablePullup(bit)               {*bit ## _PORT |= _b(bit);}
#define disablePullup(bit)              {*bit ## _PORT &= ~_b(bit);}
#define setHigh(bit)                    {*bit ## _PORT |= _b(bit);}
#define setLow(bit)                     {*bit ## _PORT &= ~_b(bit);}
#define toggle(bit)                     {*bit ## _PIN |= _b(bit);}
#define isHigh(bit)                     (*bit ## _PIN & _b(bit))
#define isLow(bit)                      (!(*bit ## _PIN & _b(bit)))

// use the following variable naming convention for these macros
//volatile uint8_t *FOO[BAR] = {&DDRC, &DDRC};
//volatile uint8_t *FOO[BAR] = {&PINC, &PINC};
//volatile uint8_t *FOO[BAR] = {&PORTC, &PORTC};
//uint8_t FOO[BAR] = {PC1, PC2};
#define arrSetOutput(bitArr, i)         {*bitArr ## _DDR[i] |= _b(bitArr[i]);}
#define arrSetInput(bitArr, i)          {*bitArr ## _DDR[i] &= ~_b(bitArr[i]);}
#define arrEnablePullup(bitArr, i)      {*bitArr ## _PORT[i] |= _b(bitArr[i]);}
#define arrDisablePullup(bitArr, i)     {*bitArr ## _PORT[i] &= ~_b(bitArr[i]);}
#define arrSetHigh(bitArr, i)           {*bitArr ## _PORT[i] |= _b(bitArr[i]);}
#define arrSetLow(bitArr, i)            {*bitArr ## _PORT[i] &= ~_b(bitArr[i]);}
#define arrToggle(bitArr, i)            {*bitArr ## _PIN[i] |= _b(bitArr[i]);}
#define arrIsHigh(bitArr, i)            (*bitArr ## _PIN[i] & _b(bitArr[i]))
#define arrIsLow(bitArr, i)             (!(*bitArr ## _PIN[i] & _b(bitArr[i])))

#endif //AVR_BIT_FUNCS
