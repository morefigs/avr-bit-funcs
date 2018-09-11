#ifndef AVR_BIT_FUNCS
#define AVR_BIT_FUNCS

#ifndef _AVR_SFR_DEFS_H_
#include <inttypes.h>
#define _BV(bit) (1UL << (bit))
#define _MMIO_BYTE(addr) (*(volatile uint8_t *)(addr))
#  if __AVR_ARCH__ >= 100
#    define __SFR_OFFSET 0x00
#  else
#    define __SFR_OFFSET 0x20
#  endif
#endif

// register offsets
#define PA 0x00
#define PB 0x03
#define PC 0x06
#define PD 0x09
#define PE 0x0C
#define PF 0x0F
#define PG 0x12
// these ports are slower to manipulate due to having 16-bit addresses
#define PH 0x100
#define PJ 0x103
#define PK 0x106
#define PL 0x109

#define OFFSET_ADDR(addr)   ((addr) < 0x80 ? (addr) + __SFR_OFFSET : (addr))
#define SET_OUTPUT(pin)     (_MMIO_BYTE(OFFSET_ADDR((pin)[0] + 0x1)) |=  _BV((pin)[1]))
#define SET_INPUT(pin)      (_MMIO_BYTE(OFFSET_ADDR((pin)[0] + 0x1)) &= ~_BV((pin)[1]))
#define ENABLE_PULLUP(pin)  (_MMIO_BYTE(OFFSET_ADDR((pin)[0] + 0x2)) |=  _BV((pin)[1]))
#define DISABLE_PULLUP(pin) (_MMIO_BYTE(OFFSET_ADDR((pin)[0] + 0x2)) &= ~_BV((pin)[1]))
#define SET_HIGH(pin)       (_MMIO_BYTE(OFFSET_ADDR((pin)[0] + 0x2)) |=  _BV((pin)[1]))
#define SET_LOW(pin)        (_MMIO_BYTE(OFFSET_ADDR((pin)[0] + 0x2)) &= ~_BV((pin)[1]))
#define TOGGLE(pin)         (_MMIO_BYTE(OFFSET_ADDR((pin)[0])) |= _BV((pin)[1]))
#define IS_HIGH(pin)        (_MMIO_BYTE(OFFSET_ADDR((pin)[0])) & _BV((pin)[1]))
#define IS_LOW(pin)         (!IS_HIGH(pin))

#endif // AVR_BIT_FUNCS
