//	Atmega328Pins.h
//  Eckels
//
// Macros and bitmasks specifically for ATMEGA328P Microcontroller
// BitMasks defining pins are specific to the Arduino Uno board.
// Pins reference the numbers on the headers.Four extra bits are
// appended onto these pins masks, defining the port they are associated with.
// Examples can be seen below with the definitions.
// 
// HISTORY:
// Initial release       Eckels 11 - 29 - 18
// Memory Mapped IO      Eckels 12 - 6  - 18
//
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h> 
#include <inttypes.h>


//Macros for DDR port direction
#define INPUT 0
#define OUTPUT 1

//Macros for pin states
#define HIGH 1
#define LOW 0

//Macros to mask out bits and pins
#define bitMsk 0xFF
#define portMsk 0xF00

//Inline Macro to get bits from pin number
#define pinToBits(p,Msk) p & Msk

//Inline Macro to get port from bit
#define pinToPort(p,Msk) (p & Msk) >> 0x8

// Macros for ports.B - D = > 2 - 4 in binary
#define PORTA_MSK 0x1
#define PORTB_MSK 0x2
#define PORTC_MSK 0x3
#define PORTD_MSK 0x4
#define PORTE_MSK 0x5
#define PORTF_MSK 0x6
#define PORTG_MSK 0x7

//Macros for Memory mapped IO
#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
//Ofsett of register in ram
#define __SFR_OFFSET 0x20
//Adding offset to register pointer
#define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + __SFR_OFFSET)

// Macros to map ports to common names
#define DIRA _SFR_IO8(0x04)//Not Real Register
#define DIRB _SFR_IO8(0x04)
#define DIRC _SFR_IO8(0x07)
#define DIRD _SFR_IO8(0x0A)
#define DIRE _SFR_IO8(0x04)//Not Real Register
#define DIRF _SFR_IO8(0x04)//Not Real Register
#define DIRG _SFR_IO8(0x04)//Not Real Register

#define READA _SFR_IO8(0x03)//Not Real Register
#define READB _SFR_IO8(0x03)
#define READC _SFR_IO8(0x06)
#define READD _SFR_IO8(0x09)
#define READE _SFR_IO8(0x03)//Not Real Register
#define READF _SFR_IO8(0x03)//Not Real Register
#define READG _SFR_IO8(0x03)//Not Real Register

#define WRITEA _SFR_IO8(0x05)//Not Real Register
#define WRITEB _SFR_IO8(0x05)
#define WRITEC _SFR_IO8(0x08)
#define WRITED _SFR_IO8(0x0B)
#define WRITEE _SFR_IO8(0x05)//Not Real Register
#define WRITEF _SFR_IO8(0x05)//Not Real Register
#define WRITEG _SFR_IO8(0x05)//Not Real Register

//Macros for bin assignments.
#define P0 0x401
#define P1 0x402
#define P2 0x404
#define P3 0x408
#define P4 0x410
#define P5 0x420
#define P6 0x440
#define P7 0x480
#define P8 0x201
#define P9 0x202
#define P10 0x204
#define P11 0x208
#define P12 0x210
#define P13 0x220
#define A0 0x301
#define A1 0x302
#define A2 0x304
#define A3 0x308
#define A4 0x310
#define A5 0x320

//Macro for built in Hardware
#define Led1 P13
#define Tx P1
#define Rx P0