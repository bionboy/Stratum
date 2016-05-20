#include "SparkIntervalTimer/SparkIntervalTimer.h"
#include "SoftPWM/SoftPWM.h"

SYSTEM_MODE(SEMI_AUTOMATIC);

uint8_t chan[3][3] = {{D5, D4, D1}, {D0, A5, A4}, {WKP, A3, A2}}; 
uint8_t state[3][3];

void setup() {
  pinMode(D8, INPUT);
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
  if (D8 == HIGH) {
    Particle.connect();
  } else {
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
  delay(2000);
 }
}
