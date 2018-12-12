/*<Pic32Tester.c>
<Mike Eckels >

#####################################################

Pic32Tester.C is a test program to check the API. This
is also useful as an example to the user of The API. 
Here, only input and outputs are shown, however documentation
in the API goes into further detail of it's use. 

SCOPE:
Define MCU and include headers
Clear IO of garbage data
Setup INPUTS and OUTPUTS
Conditionals for logic
Turn on/off IO on given case

HISTORY :
Initial Release 					Eckels 9  - 10 - 18
interrupts added					Eckels 10 - 26 - 18
New API								Eckels 11 - 5  - 18

TEST PLAN :.

view on scope and look at waveforms

if (looks good())
	{
	Submit();
else
	{
	Fix();
	}
}

************************************************************************** */
#ifdef pic18
#include "pic18Pins"
#endif

#ifdef pic32
#include "pic32Pins.h"
#endif

#ifdef Arduino 
#include "AtMega328Pins.h"
#endif

void main()
{
	//Reset IO to clear garbage and setup timers
	resetIO();

	//Setting up ports for input and output
	pinDirection(Led1, OUTPUT);
	pinDirection(L1, INPUT);


	//Conditionals
	while (true)//Loop forever
	{
		if (readPin(Sw1))//Check switch state
		{
			setPin(Led1, HIGH, 0);//Led1 ON
		}
		else
		{
			setPin(Led1, LOW, 0);//Led2 OFF
		}
	}
}
