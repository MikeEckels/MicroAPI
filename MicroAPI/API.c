//	pic32API.c
//  Eckels
//
// Contains configuration bits and functions specific to the pic32Mx795F512L
// Microcontroller.
// Void Reset()
//		Function: Resets all registers to known values and sets up timer 1
//		INPUT: NONE
//		RETURN: NONE
//
// bool pinDirection()
//		Function: sets direction of pins. Input or Output
//		INPUT: Pin Number, Direction
//		OUTPUT: 1 if no errors, 0 if errors
//
// void setPin()
//		Function: Sets pin HIGH or LOW, or inverts from current state
//		INPUT: Pin Number, State, invert? (1 or 0 --> Yes or NO)
//		OUTPUT: NONE
//
// bool readPin()
//		Function: reads the state of a pin
//		INPUT: Pin number
//		OUTPUT: 1 or 0 
//
// void enableInt()
//		Function: Setupt change notification interrupts 
//		INPUT: Pin number, Pullups? (1 or 0 --> Yes or NO)
//		OUTPUT: NONE
//
// void Wait()
//		Function: Delays....
//		INPUT: length of delay in ms
//		OUTPUT: NONE
// 
// HISTORY:
// Initial release       Eckels 11 - 5 - 18
// Delay added			 Eckels 11 - 20 - 18
// Arduino Suppot		 Eckels 12 - 6  - 18

///////////////////////////////////////////////////////////////////////////////
volatile unsigned long count;

#ifdef pic18
#include "pic18Pins"
#endif

#ifdef pic32
#include "pic32Pins.h"

// Configuration Bits
unsigned int timer1Period = 10000;      // Period for timer one at 1ms pulses
#pragma config FNOSC    = PRIPLL        // Oscillator Selection
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider 
#pragma config FPLLMUL  = MUL_20        // PLL Multiplier
#pragma config FPLLODIV = DIV_1         // PLL Output Divider
#pragma config FPBDIV   = DIV_1         // Peripheral Clock divisor
#pragma config FWDTEN   = OFF           // Watchdog Timer
#pragma config WDTPS    = PS1           // Watchdog Timer Postscale
#pragma config FCKSM    = CSDCMD        // Clock Switching & Fail Safe Clock Monitor
#pragma config OSCIOFNC = OFF           // CLKO Enable
#pragma config POSCMOD  = XT            // Primary Oscillator
#pragma config IESO     = OFF           // Internal/External Switch-over
#pragma config FSOSCEN  = OFF           // Secondary Oscillator Enable
#pragma config CP       = OFF           // Code Protect
#pragma config BWP      = OFF           // Boot Flash Write Protect
#pragma config PWP      = OFF           // Program Flash Write Protect
#pragma config ICESEL   = ICS_PGx2      // ICE/ICD Comm Channel Select
#pragma config DEBUG    = OFF           // Debugger Disabled for Starter Kit
#endif

#ifdef Arduino 
#include "AtMega328Pins.h"

#ifndef bool
#define bool _Bool
#define true 1
#define false 0
#endif

#endif

void resetIO()
{

#ifdef pic32
	//Set all direction registers to a known state. 
	DIRA = 0xFFFF;
	DIRB = 0xFFFF;
	DIRC = 0xFFFF;
	DIRD = 0xFFFF;
	DIRE = 0xFFFF;
	DIRF = 0xFFFF;
	DIRG = 0xFFFF;

	//set all read registers to a known state.
	READA = READA & (~0xFFFF);
	READB = READB & (~0xFFFF);
	READC = READC & (~0xFFFF);
	READD = READD & (~0xFFFF);
	READE = READE & (~0xFFFF);
	READF = READF & (~0xFFFF);
	READG = READG & (~0xFFFF);

	//Setup timer1 for delay function
	OpenTimer1(T1_ON | T1_PS_1_8 | T1_SOURCE_INT, timer1Period);
	//OpenTimer1(T1_ON | T1_SOURCE_INT, 0xffff);
	ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_2);

	// enable multivector interrupts
	INTEnableSystemMultiVectoredInt();
#endif

#ifdef Arduino
	//Set all direction registers to a known state.
	DIRB = 0xFF;
	DIRC = 0xFF;
	DIRD = 0xFF;

	//set all read registers to a known state.
	READB = READB & (~0xFF);
	READC = READC & (~0xFF);
	READD = READD & (~0xFF);
#endif

#ifdef pic18
	//Timer setup code here
#endif
}

//sets pin to either inputs or outputs
bool pinDirection(unsigned int pinNum, unsigned char Direction)
{
	unsigned short int bits = 0;
	unsigned char portBits = 0;

	//cool macros. See pins.h for explination
    bits = pinToBits(pinNum, bitMsk);
	portBits = pinToPort(pinNum, portMsk);

	switch (portBits)
	{
	  case PORTA_MSK:
		  if (Direction == INPUT) DIRA = DIRA | bits;
		  else DIRA = DIRA & (~bits);
		  break;
	  case PORTB_MSK:
		  if (Direction == INPUT) DIRB = DIRB | bits;
		  else DIRB = DIRB & (~bits);
		  break;
	  case PORTC_MSK:
		  if (Direction == INPUT) DIRC = DIRC | bits;
		  else DIRC = DIRC & (~bits);
		  break;
	  case PORTD_MSK:
		  if (Direction == INPUT) DIRD = DIRD | bits;
		  else DIRD = DIRD & (~bits);
		  break;
	  case PORTE_MSK:
		  if (Direction == INPUT) DIRE = DIRE | bits;
		  else DIRE = DIRE & (~bits);
		  break;
	  case PORTF_MSK:
		  if (Direction == INPUT) DIRF = DIRF | bits;
		  else DIRF = DIRF & (~bits);
		  break;
	  case PORTG_MSK:
		  if (Direction == INPUT) DIRG = DIRG | bits;
		  else DIRG = DIRG & (~bits);
		  break;
	  default: return(false);
	}
	return(true);
}

//If invert bit is LOW, setPin acts normal and either writes a pin HIGH or LOW. 
//If invert bit is HIGH, setPin inverts the pins state from its previous state, ignoring the 'state' parameter
void setPin(unsigned int pinNum, bool state, bool invert)
{
	unsigned short int bits = 0;
	unsigned char portBits = 0;

	bits = pinToBits(pinNum, bitMsk);
	portBits = pinToPort(pinNum, portMsk);

	switch (portBits)
	{
	  case PORTA_MSK:
		  if (invert) WRITEA = WRITEA ^ bits;
		  else if (state == HIGH) WRITEA = WRITEA | bits;
		  else WRITEA = WRITEA & (~bits);
		  break;
	  case PORTB_MSK:
		  if (invert) WRITEB = WRITEB ^ bits;
		  else if (state == HIGH) WRITEB = WRITEB | bits;
		  else WRITEB = WRITEB & (~bits);
		  break;
	  case PORTC_MSK:
		  if (invert) WRITEC = WRITEC ^ bits;
		  else if (state == HIGH) WRITEC = WRITEC | bits;
		  else WRITEC = WRITEC & (~bits);
		  break;
	  case PORTD_MSK:
		  if (invert) WRITED = WRITED ^ bits;
		  else if (state == HIGH) WRITED = WRITED | bits;
		  else WRITED = WRITED & (~bits);
		  break;
	  case PORTE_MSK:
		  if (invert) WRITEE = WRITEE ^ bits;
		  else if (state == HIGH) WRITEE = WRITEE | bits;
		  else WRITEE = WRITEE & (~bits);
		  break;
	  case PORTF_MSK:
		  if (invert) WRITEF = WRITEF ^ bits;
		  else if (state == HIGH) WRITEF = WRITEF | bits;
		  else WRITEF = WRITEF & (~bits);
		  break;
	  case PORTG_MSK:
		  if (invert) WRITEG = WRITEG ^ bits;
		  else if (state == HIGH) WRITEG = WRITEG | bits;
		  else WRITEG = WRITEG & (~bits);
		  break;
	}
}

//reads the state of a pin. Returns HIGH or LOW ie. 1 or 0
bool readPin(unsigned int pinNum)
{
	unsigned short int bits = 0;
	unsigned char portBits = 0;

	bits = pinToBits(pinNum, bitMsk);
	portBits = pinToPort(pinNum, portMsk);
	bool state = false;

	switch (portBits)
	{
	case PORTA_MSK:
		if (READA & bits) state = false;
		else state = true;
		break;
	case PORTB_MSK:
		if (READB & bits) state = false;
		else state = true;
		break;
	case PORTC_MSK:
		if (READC & bits) state = false;
		else state = true;
		break;
	case PORTD_MSK:
		if (READD & bits) state = false;
		else state = true;
		break;
	case PORTE_MSK:
		if (READE & bits) state = false;
		else state = true;
		break;
	case PORTF_MSK:
		if (READF & bits) state = false;
		else state = true;
		break;
	case PORTG_MSK:
		if (READG & bits) state = false;
		else state = true;
		break;
	}
	return(state);
}

//enables intrrupts. sets notification registers and priority levels
/*
void enableInt(unsigned long pinNum, bool pullups)
{
	unsigned long bits = 0;

	bits = (pinNum | CNEN);    //Bitwise or to extract what pin fired the interrupt

	CNCON = 0x8000;            //Enable Change Notice module
	CNEN = bits;               //Enable individual CN pin
	if (pullups) CNPUE = bits; //Enable weak pull ups for pin

	//read port(s) to clear mismatch on change notice pins. IDK how this works so ill read them all...??
	READA;
	READB;
	READC;
	READD;
	READE;
	READF;
	READG;

	IPC6SET = 0x00170000; //Set priority level=5 Subpriority level=3
	IFS1CLR = 0x0001;     //Clear the interrupt flag status bit
	IEC1SET = 0x0001;     //Enable Change Notice interrupts
}
*/
//delay function takes in argumet and delays by that amount
void wait(long time)
{
	unsigned long start = (count * 1000);

	while (time > 0)
	{
		if (((count * 1000) - start) >= 1000)
		{
			time--;
			start += 1000;
		}
	}
}

#ifdef pic32
void __ISR(_TIMER_1_VECTOR, ipl2) _Timer1Handler(void)
{
	count += 1;
	mT1ClearIntFlag();
}
#endif