# MicroAPI
A custom API for Arduino Uno, Pic32, and Pic18 Microcontrollers. This API is written similar to Arduino's, providing simple use with command like "setPin", and "readPin".

# Architectural Overview
This API supports multiple microcontrollers, as well as the ability to easily expand for future devices. This is accomplished by creating a header file for each microcontroller. These headers contain macros and bitmasks used to uniquely define all pins, their respective ports as well as any special function registers and hardware defined devices (like built-in leds/switches). This provides a common translation layer between MCU's and the API functions. 

## Macros
Four simple macros are used to define the states of "INPUT", "OUTPUT", "LOW", and "HIGH" allowing the use of binary or the literal. Two other main macros are used to derive a port from a pin mask, or a pins bit number from a pin mask. 

## BitMasks
BitMasks define the pin name to a specific register and bit in memory. These definitions are found in the datasheet of the chip. Each mask is 8 bits wide with an extra 4 bits appended to denote the register it belongs to. For example, pin P0 = 0x401 which is 0100 0000 0001 in binary. This means the pin is on bit #1 in the register corresponding to portMask 0x1.

# Available Function Calls
- void Reset(): Resets all registers to known values and configures timers.
  - INPUTS: NONE
  - RETURN: NONE
- bool pinDirection(): Sets the direction of a pin as input or output.
  - INPUTS: pinNumber, direction
  - RETURN: 1 if no errors, 0 if errors
- void setPin(): Sets pin HIGH (1) or LOW (0), or inverts current state.
  - INPUTS: pinNumber, state, invert? (1 or 0 --> Yes or NO)
  - RETURN: NONE
- bool readPin(): Reads the current state of a pin.
  - INPUTS: pinNumber
  - RETURN: 1 or 0
- void enableInt(): Setup change notification interrupts.
  - INPUTS: pNumber, pullups? (1 or 0 --> Yes or NO)
  - RETURN: NONE
- void wait(): Delays by a specified time.
  - INPUTS: time in ms
  - RETURN: NONE
