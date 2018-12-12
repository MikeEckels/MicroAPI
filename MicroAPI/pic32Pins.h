//	pic32Pins.h
//  Eckels
//
// Macros and bitmasks specifically for Pic32Mx795F512L Microcontroller
// BitMasks defining pins are specific to the Starterkit breakout board.
// Pins reference the numbers on the headers. L(Left) meaning J10 and 
// R(Right) meaning J11. Four extra bits are appended onto these pins
// masks, defining the port they are associated with. Examples can be 
// seen below with the definitions.
// 
// HISTORY:
// Initial release       Eckels 11 - 5 - 18
// Common Port names     Eckels 12 - 6 - 18
// Bug fixes in pin def  Eckels 12 - 9 - 18
//
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <plib.h>  

//Macros for TRIS direction
#define INPUT 1
#define OUTPUT 0

//Macros for pin states
#define HIGH 1
#define LOW 0

//Macros to mask out bits and pins
#define bitMsk 0xFFFF
#define portMsk 0xF0000

//Inline Macro to get bits from pin number
#define pinToBits(p,Msk) p & Msk

//Inline Macro to get port from bit
#define pinToPort(p,Msk) (p & Msk) >> 0x10

//Macros for ports. A-G => 1-7 in binary
#define PORTA_MSK 0x1
#define PORTB_MSK 0x2
#define PORTC_MSK 0x3
#define PORTD_MSK 0x4
#define PORTE_MSK 0x5
#define PORTF_MSK 0x6
#define PORTG_MSK 0x7

//Macros to map ports to common name
#define DIRA TRISA
#define DIRB TRISB
#define DIRC TRISC
#define DIRD TRISD
#define DIRE TRISE
#define DIRF TRISF
#define DIRG TRISG

#define READA PORTA
#define READB PORTB
#define READC PORTC
#define READD PORTD
#define READE PORTE
#define READF PORTF
#define READG PORTG

#define WRITEA LATA
#define WRITEB LATB
#define WRITEC LATC
#define WRITED LATD
#define WRITEE LATE
#define WRITEF LATF
#define WRITEG LATG

//Macros for J10 pins. L means left. first 4bits are the port. Other 15bits are the pin. 0 Means pin isnt GPIO. 
#define L1 0x78000 // Ex:0111 1000 0000 0000 0000 => Port G bit 15 (RG15)
#define L3 0x71000
#define L4 0x74000
#define L5 0x50080
#define L6 0x50040
#define L7 0x50020
#define L8 0x50010
#define L9 0x50008
#define L10 0x50004
#define L11 0x50002
#define L12 0x50001
#define L13 0x40020
#define L14 0x40010
#define L15 0x40800
#define L16 0x40400
#define L17 0x34000
#define L18 0x30002
#define L19 0x30004
#define L20 0x30008
#define L21 0x30010
#define L23 0
#define L24 0
#define L25 0
#define L26 0
#define L29 0x20020
#define L30 0
#define L31 0
#define L32 0
#define L33 0
#define L34 0
#define L35 0
#define L36 0
#define L37 0
#define L38 0
#define L41 0
#define L42 0
#define L43 0
#define L44 0
#define L46 0
#define L47 0x20400
#define L48 0x20800
#define L49 0x21000
#define L50 0x22000
#define L51 0
#define L52 0
#define L53 0
#define L54 0
#define L55 0
#define L56 0
#define L57 0
#define L58 0
#define L59 0x24000
#define L60 0x28000

//Macros for J11 pins. Same scheme as described above
#define R1 0x10040
#define R3 0x10080
#define R4 0x72000
#define R5 0x70002
#define R6 0x70001
#define R7 0x60001
#define R8 0x60002
#define R9 0x42000
#define R10 0x41000
#define R11 0x40080
#define R12 0x40040
#define R13 0
#define R14 0x32000
#define R15 0
#define R16 0
#define R17 0x40004
#define R18 0x40008
#define R19 0x40001
#define R20 0x40002
#define R21 0
#define R23 0
#define R24 0
#define R25 0x40100
#define R26 0x40200
#define R29 0
#define R30 0
#define R31 0
#define R32 0
#define R33 0
#define R34 0
#define R35 0
#define R36 0
#define R37 0
#define R38 0
#define R41 0
#define R42 0
#define R43 0
#define R44 0
#define R46 0
#define R47 0
#define R48 0
#define R49 0
#define R50 0
#define R51 0
#define R52 0
#define R53 0
#define R54 0x10020//Acts odd as digital out
#define R55 0
#define R56 0x10010//Acts odd as digital out
#define R57 0
#define R58 0x10002//Acts odd as digital out
#define R59 0
#define R60 0x10001//Acts odd as digital out

//Macros for Change Notification Pins
#define CN0 0
#define CN1 0x2
#define CN2 0x4
#define CN3 0x8
#define CN4 0x10
#define CN5 0x20
#define CN6 0x40
#define CN7 0x80
#define CN8 0x100
#define CN9 0x200
#define CN10 0x400
#define CN11 0x800
#define CN12 0x1000
#define CN13 0x2000
#define CN14 0x4000
#define CN15 0x8000
#define CN16 0x10000
#define CN17 0x20000
#define CN18 0x40000
#define CN19 0x80000
#define CN20 0x100000
#define CN21 0x200000

//Macros for built in hardware
#define Led1 R19
#define Led2 R20
#define Led3 R17
#define Sw1 R12
#define Sw2 R11
#define Sw3 R9

//Macros to setup timers
#define configPERIPHERAL_CLOCK_HZ	(40000000UL)
#define MS_TO_CLOCK_CYCLE(ms) ms*(configPERIPHERAL_CLOCK_HZ/1000)