#include "SparkIntervalTimer/SparkIntervalTimer.h"
#include "SoftPWM/SoftPWM.h"
//rgb channels for the 3 rgb leds

const int r0 = D0;
const int g0 = D1;
const int b0 = D2;
const int r1 = D3;
const int g1 = A4;
const int b1 = A5;
const int r2 = WKP;
const int g2 = RX;
const int b2 = TX;

int rstate0;
int gstate0;
int bstate0;
int rstate1;
int gstate1;
int bstate1;
int rstate2;
int gstate2;
int bstate2;

void setup() {
//set pwm pins as outputs
    pinMode(r0,OUTPUT);
    pinMode(g0,OUTPUT);
    pinMode(b0,OUTPUT);
    pinMode(r1,OUTPUT);
    pinMode(g1,OUTPUT);
    pinMode(b1,OUTPUT);
    pinMode(r2,OUTPUT);
    pinMode(g2,OUTPUT);
    pinMode(b2,OUTPUT);
//set initial state of pwm outputs
    rstate0 = 0;
    gstate0 = 0;
    bstate0 = 0;
    rstate1 = 0;
    gstate1 = 0;
    bstate1 = 0;
    rstate2 = 0;
    gstate2 = 0;
    bstate2 = 0;
//begin softPWM and set fade time
    SoftPWMBegin();
    SoftPWMSetFadeTime(ALL,100,100);
//turn all pins off
    SoftPWMSet(r0, 0);
    SoftPWMSet(g0, 0);
    SoftPWMSet(b0, 0);
    SoftPWMSet(r1, 0);
    SoftPWMSet(g1, 0);
    SoftPWMSet(b1, 0);
    SoftPWMSet(r2, 0);
    SoftPWMSet(g2, 0);
    SoftPWMSet(b2, 0);
}
  
void loop(){
    randomSeed(analogRead(A0));
//set pwm output values
    SoftPWMSet(r0,rstate0);
    SoftPWMSet(g0,gstate0);
    SoftPWMSet(b0,bstate0);
    
    SoftPWMSet(r1,rstate1);
    SoftPWMSet(g1,gstate1);
    SoftPWMSet(b1,bstate1);
    
    SoftPWMSet(r2,rstate2);
    SoftPWMSet(g2,gstate2);
    SoftPWMSet(b2,bstate2);
//shift pwm states
    rstate2 = rstate1;
    gstate2 = rstate1;
    bstate2 = rstate1;
    
    rstate1 = rstate0;
    gstate1 = rstate0;
    bstate1 = rstate0;
    
    rstate0 = random(255);
    gstate0 = random(255);
    bstate0 = random(255);
    
    delay(10000);
}
