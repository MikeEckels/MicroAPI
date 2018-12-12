//	pic18Pins.h
//  Eckels
//
// Macros and bitmasks specifically for pic18 Microcontroller
// BitMasks defining pins are specific to the expansion board.
// Pins reference the numbers on the headers.Four extra bits are
// appended onto these pins masks, defining the port they are associated with.
// Examples can be seen below with the definitions.
// 
// HISTORY:
// Initial release       Eckels 11 - 30 - 18
//
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h> 

//Macros for DDR port direction
#define INPUT 0
#define OUTPUT 1

//Macros for pin states
#define HIGH 1
#define LOW 0