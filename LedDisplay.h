/*
	Created by Paul Lancaster on the 23/07/2017
	Controls the 3461BS 4 digit 7 segment led display
	which uses a common anode for each digit
*/
#ifndef LedDisplay_h
#define LedDisplay_h
#include "Arduino.h"

/* 
Default time to delay each digit of the number display in milliseconds
time_for_each_number = DISPLAY_DELAY * display_digits
Eg. Time for each number = 5 * 4 = 20ms f = 1/T = 1/0.02 = 50Hz
*/
#define DEFAULT_DISPLAY_DELAY 5

class LedDisplay
{
	public:
		/*
			Initializes the led display. The A_Pin, B_Pin... are the cathode pins for the display. See
			the 3461BS display datasheet for what pin theses correspond to on the physical device.
		*/
		LedDisplay(char, char, char, char,
char, char, char, char, char, char, char);
		/*
			Displays a number on an LED display
			This needs to be called each loop otherwise the number will only display once
			This is blocking.
			Returns true if successful and false if not.
		*/
		boolean displayNumber(int);
		/*
			Displays the err output (4 dashes)
		*/
		void displayErr();
		/*
			Clears the display
		*/
		void displayClear();
		/*
			Set the refresh rate for each digit (the time to display each digit for in milliseconds)
		*/
		void setRefreshRate(unsigned int);
		/* 
			Display the given value at the given digit
			This value must be between -1 and 9 inclusive with -1 corresponding to 
			the negative dash signal. The digit must be between 0 and 3 with 0 
			corresponding to the first digit and 3 to the fourth digit. 
			Returns false if the display didn't correctly display the value
		*/
		boolean displayVal(int, int);
		
	private:
		/*
			Sends the digital dash signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayDash();
		/*
			Sends the zero display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayZero();
		/*
			Sends the one display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayOne();
		/*
			Sends the two display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayTwo();
		/*
			Sends the three display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayThree();
		/*
			Sends the four display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayFour();
		/*
			Sends the five display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayFive();
		/*
			Sends the six display signal signal to the device. 
			This requires the desired digits anode being on
		*/
		void displaySix();
		/*
			Sends the seven display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displaySeven();
		/*
			Sends the eight display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayEight();
		/*
			Sends the nine display signal to the device. 
			This requires the desired digits anode being on
		*/
		void displayNine();
};
#endif