#include "SparkIntervalTimer/SparkIntervalTimer.h"
#include "SoftPWM/SoftPWM.h"

uint8_t chan[3][3] = {{D0, D2, D4}, {D6, A1, A2}, {A3, A4, A5}}; 
uint8_t state[3][3];

void setup() {
  SoftPWMBegin();                     //begin softPWM and set fade time

  for (int i = 0; i < 3; i++){        //set pwm pins as outputs
    for(int c = 0; c < 3; c++)
    {
      pinMode(chan[i][c], OUTPUT);
      SoftPWMSet(chan[i][c], state[i][c] = 0);
    }
  }

  SoftPWMSetFadeTime(ALL,100,100);
}

void loop(){
  randomSeed(analogRead(A0));

  for (int i = 0; i < 3; i++){        //set pwm pins as outputs
    for(int c = 0; c < 3; c++)
    {
      SoftPWMSet(chan[2-i][c], state[2-i][c]);
      if (i < 2)
        state[2-i][c] = state[2-i-1][c];
      else
        state[2-i][c] = random(255);
    }
  }

  delay(10000);
}
