#include "SparkIntervalTimer/SparkIntervalTimer.h"
#include "SoftPWM/SoftPWM.h"

uint8_t chan[9] = {D0, D2, D4, D6, A1, A2, A3, A4, A5};    //rgb channels for the 3 rgb leds

uint8_t state0[3];
uint8_t state1[3];
uint8_t state2[3];

void setup() {
    for (int i = 0; i < 9; i++){        //set pwm pins as outputs
        pinMode(chan[i], OUTPUT);
    }

    for (int i = 0; i <3; i++){         //set initial state of pwm outputs
        state0[i] = 0;
    }
    for (int i = 0; i <3; i++){
        state1[i] = 0;
    }
    for (int i = 0; i <3; i++){
        state2[i] = 0;
    }

    SoftPWMBegin();                     //begin softPWM and set fade time
    SoftPWMSetFadeTime(ALL,100,100);

    for (int i = 0; i < 9; i++){        //turn all pins off
    SoftPWMSet(chan[i], 0);
    }
}
  
void loop(){
    randomSeed(analogRead(A0));

    for (int i = 0; i < 3; i++){        //set pwm output values
    SoftPWMSet(chan[i],state0[i]);
    }
    for (int i = 0; i < 3; i++){
    SoftPWMSet(chan[i + 3],state1[i]);
    }
    for (int i = 0; i < 3; i++){
    SoftPWMSet(chan[i + 7],state2[i]);
    }

    for (int i = 0; i < 3; i++){        //shift pwm states
    state2[i] = state1[i];
    }
    for (int i = 0; i < 3; i++){
    state1[i] = state0[i];
    }
    for (int i = 0; i < 3; i++){
    state0[i] = random(255);
    }
    
    delay(10000);
}
