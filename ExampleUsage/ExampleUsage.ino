#include <LedDisplay.h>

// Pins for LED display
#define PIN_DIG_1_ANODE 14
#define PIN_DIG_2_ANODE 15
#define PIN_DIG_3_ANODE 16
#define PIN_DIG_4_ANODE 17
#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5
#define PIN_E 6
#define PIN_F 7
#define PIN_G 8

LedDisplay ledDisplay(PIN_DIG_1_ANODE,PIN_DIG_2_ANODE,PIN_DIG_3_ANODE,PIN_DIG_4_ANODE,
PIN_A,PIN_B,PIN_C,PIN_D,PIN_E,PIN_F,PIN_G);

void setup() {
  
}

void loop() {
 
  unsigned int refreshRate = 5;
  ledDisplay.setRefreshRate(refreshRate);
  
  for(int i=-999; i < 10000; i++){
    ledDisplay.displayNumber(i);
  }

  ledDisplay.displayErr();
  
}
