/*
	Created by Paul Lancaster on the 23/07/2017.
	Controls the 3461BS LED display
*/

#include "LedDisplay.h"

// Variables storing the pins to use
char pin_dig_1_anode, pin_dig_2_anode, pin_dig_3_anode, pin_dig_4_anode;
char pin_A, pin_B, pin_C, pin_D, pin_E, pin_F, pin_G;

// Time to display each digit for in milliseconds
unsigned int display_delay; 

LedDisplay::LedDisplay(
char pinDigAnode_1, char pinDigAnode_2, char pinDigAnode_3, char pinDigAnode_4,
char A_Pin, char B_Pin, char C_Pin, char D_Pin, char E_Pin, char F_Pin, char G_Pin){
	pin_dig_1_anode = pinDigAnode_1;
	pin_dig_2_anode = pinDigAnode_2;
	pin_dig_3_anode = pinDigAnode_3;
	pin_dig_4_anode = pinDigAnode_4;
	pin_A = A_Pin;
	pin_B = B_Pin;
	pin_C = C_Pin;
	pin_D = D_Pin;
	pin_E = E_Pin;
	pin_F = F_Pin;
	pin_G = G_Pin;
	display_delay = DEFAULT_DISPLAY_DELAY;
	
	pinMode(pin_dig_1_anode, OUTPUT);
	pinMode(pin_dig_2_anode, OUTPUT);
	pinMode(pin_dig_3_anode, OUTPUT);
	pinMode(pin_dig_4_anode, OUTPUT);

	pinMode(pin_A, OUTPUT);
	pinMode(pin_B, OUTPUT);
	pinMode(pin_C, OUTPUT);
	pinMode(pin_D, OUTPUT);
	pinMode(pin_E, OUTPUT);
	pinMode(pin_F, OUTPUT);
	pinMode(pin_G, OUTPUT);
}

void LedDisplay::setRefreshRate(unsigned int refreshRate){
	display_delay = refreshRate;
}

boolean LedDisplay::displayNumber(int number) {
  if (number > 9999 || number < -999) {
    displayErr();
    return false;
  }

  int thousands = (number / 1000);
  number = number - thousands * 1000;
  int hundreds = (number / 100);
  number = number - hundreds * 100;
  int tens = (number / 10);
  number = number - tens * 10;

  if (number < 0) {
    displayVal(-1, 0);
    displayVal(-hundreds, 1);
    displayVal(-tens, 2);
    displayVal(-number, 3);
  } else {
    displayVal(thousands, 0);
    displayVal(hundreds, 1);
    displayVal(tens, 2);
    displayVal(number, 3);
  }

  return true;
}

boolean LedDisplay::displayVal(int number, int digit) {
  displayClear();

  switch (digit) {
    case 0:
      digitalWrite(pin_dig_1_anode, HIGH);
      break;
    case 1:
      digitalWrite(pin_dig_2_anode, HIGH);
      break;
    case 2:
      digitalWrite(pin_dig_3_anode, HIGH);
      break;
    case 3:
      digitalWrite(pin_dig_4_anode, HIGH);
      break;
    default:
      return false;
      break;
  }

  switch (number) {
    case 0:
      displayZero();
      break;
    case 1:
      displayOne();
      break;
    case 2:
      displayTwo();
      break;
    case 3:
      displayThree();
      break;
    case 4:
      displayFour();
      break;
    case 5:
      displayFive();
      break;
    case 6:
      displaySix();
      break;
    case 7:
      displaySeven();
      break;
    case 8:
      displayEight();
      break;
    case 9:
      displayNine();
      break;
    case -1:
      displayDash();
      break;
    default:
      return false;
      break;
  }
  delay(display_delay); // Delay so the user can briefly see the number
  return true;
}

void LedDisplay::displayErr() {
  displayClear();

  digitalWrite(pin_dig_1_anode, HIGH);
  digitalWrite(pin_dig_2_anode, HIGH);
  digitalWrite(pin_dig_3_anode, HIGH);
  digitalWrite(pin_dig_4_anode, HIGH);

  digitalWrite(pin_G, LOW);
}

void LedDisplay::displayDash() {
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displayZero() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_D, LOW);
  digitalWrite(pin_E, LOW);
  digitalWrite(pin_F, LOW);
}

void LedDisplay::displayOne() {
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
}

void LedDisplay::displayTwo() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_D, LOW);
  digitalWrite(pin_E, LOW);
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displayThree() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_D, LOW);
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displayFour() {
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_F, LOW);
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displayFive() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_D, LOW);
  digitalWrite(pin_F, LOW);
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displaySix() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_D, LOW);
  digitalWrite(pin_E, LOW);
  digitalWrite(pin_F, LOW);
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displaySeven() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
}

void LedDisplay::displayEight() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_D, LOW);
  digitalWrite(pin_E, LOW);
  digitalWrite(pin_F, LOW);
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displayNine() {
  digitalWrite(pin_A, LOW);
  digitalWrite(pin_B, LOW);
  digitalWrite(pin_C, LOW);
  digitalWrite(pin_F, LOW);
  digitalWrite(pin_G, LOW);
}

void LedDisplay::displayClear() {
  digitalWrite(pin_dig_1_anode, LOW);
  digitalWrite(pin_dig_2_anode, LOW);
  digitalWrite(pin_dig_3_anode, LOW);
  digitalWrite(pin_dig_4_anode, LOW);

  digitalWrite(pin_A, HIGH);
  digitalWrite(pin_B, HIGH);
  digitalWrite(pin_C, HIGH);
  digitalWrite(pin_D, HIGH);
  digitalWrite(pin_E, HIGH);
  digitalWrite(pin_F, HIGH);
  digitalWrite(pin_G, HIGH);
}