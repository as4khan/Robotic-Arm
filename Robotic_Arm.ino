#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myservo_1;  
#define MIN_PULSE_WIDTH 650    // variable to store the servo position
#define MAX_PULSE_WIDTH 2350
#define FREQUENCY 50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int controlGRIPPER = A0;
int controlWRIST = A1;

int motorGRIPPER = 0;
int motorWRIST = 5;

int mtrDgrGRIPPER;
int mtrDgrWRIST;

void setup(){
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void moveMOTOR(int moveDegree, int motorOut){

  int pulse_wide, pulse_width;

  pulse_wide = map(moveDegree, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide)/1000000 * FREQUENCY * 4096);
  pwm.setPWM(motorOut, 0, pulse_width);
}

int getDEGREE(int controlIn){
  int potVal; 
  int servoDegree;
  potVal = analogRead(controlIn);
  servoDegree = map(potVal, 0, 1023, 0, 180);

  return servoDegree;

}

void loop(){
  mtrDgrGRIPPER = getDEGREE(controlGRIPPER);
  moveMOTOR(mtrDgrGRIPPER, motorGRIPPER);

  mtrDgrWRIST = getDEGREE(controlWRIST);
  moveMOTOR(mtrDgrWRIST, motorWRIST);
}
