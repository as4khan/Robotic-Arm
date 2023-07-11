
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

/*
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 300

uint8_t servonum = 0;
uint8_t numberOfServos = 1;

void setup() {
  Serial.begin(9600);
  myServo.begin();
  myServo.setPWMFreq(60);
  delay(10);
}

void loop() {
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
    myServo.setPWM(servonum, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
    myServo.setPWM(servonum, 0, pulselen);
  }
  delay(500);
  
  servonum ++;
  if (servonum > numberOfServos-1) 
    servonum = 0;
}
*/