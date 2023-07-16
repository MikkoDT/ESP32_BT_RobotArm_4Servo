#include <DabbleESP32.h>
#include <Arduino.h>
#include <Servo.h>

//#define CUSTOM_SETTINGS
//#define INCLUDE_GAMEPAD_MODULE

//create servo object to control a servo
Servo leftRight;
Servo upDown;
Servo backForth;
Servo gripper;

#define leftRightPin 4
#define upDownPin 17
#define backForthPin 19
#define gripPin 23

//initial angle  for servo
int angle = 0;
int angleStep = 2;

//Servo1
int baseA = 0;
//Servo2
int elbowB = 0;
//Servo3
int shoulderC = 0;
//Servo4
int gripD = 0;

void setup() {
  
  leftRight.attach(leftRightPin);
  upDown.attach(upDownPin);
  backForth.attach(backForthPin);
  gripper.attach(gripPin);
  
  Serial.begin(9600);
  Dabble.begin("ESP32ServoController");
}

void loop() {
  Dabble.processInput();
  if (GamePad.isLeftPressed())
  {
    baseA = baseA + angleStep;
    leftRight.write(baseA);
    if(baseA>=180)
    {
      baseA = 180;
      leftRight.write(baseA);
    }
    delay(20);
  }
  else if (GamePad.isRightPressed()) 
  {
    baseA = baseA - angleStep;
    leftRight.write(baseA);
    if(baseA<=0)
    {
      baseA = 0;
      leftRight.write(baseA);
    }
    delay(20);
  }
  else if (GamePad.isUpPressed()) {
    elbowB = elbowB + angleStep;
    upDown.write(elbowB);
    if(elbowB>=90)
    {
      elbowB = 90;
      upDown.write(elbowB);
    }
    delay(20);
  }
  else if (GamePad.isDownPressed()) {
    elbowB = elbowB - angleStep;
    upDown.write(elbowB);
    if(elbowB<=0)
    {
      elbowB = 0;
      upDown.write(elbowB);
    }
    delay(20);
  }
  else if (GamePad.isTrianglePressed()) {
    shoulderC = shoulderC + angleStep;
    backForth.write(shoulderC);
    if(shoulderC>=90)
    {
      shoulderC = 90;
      backForth.write(shoulderC);
    }
    delay(20);
  }
  else if (GamePad.isCrossPressed()) {
    shoulderC = shoulderC - angleStep;
    backForth.write(shoulderC);
    if(shoulderC<=0)
    {
      shoulderC = 0;
      backForth.write(shoulderC);
    }
    delay(20);
  }
    else if (GamePad.isCirclePressed()) {
    gripD = gripD + angleStep;
    gripper.write(gripD);
    if(gripD>=90)
    {
      gripD = 90;
      gripper.write(gripD);
    }
    delay(20);
  }
    else if (GamePad.isSquarePressed()) {
    gripD = gripD - angleStep;
    gripper.write(gripD);
    if(gripD<=0)
    {
      gripD = 0;
      gripper.write(gripD);
    }
    delay(20);
  }
  else if (GamePad.isStartPressed()) 
  {
    while(baseA!=0)
    {
      baseA = baseA - 2;
      leftRight.write(baseA);
      if(baseA<=0)
      {
        baseA = 0;
        leftRight.write(baseA);
      }
      delay(20);
    }
    
    while(elbowB!=0)
    {
      elbowB = elbowB - 2;
      upDown.write(elbowB);
      if(elbowB<=0)
      {
        elbowB = 0;
        upDown.write(elbowB);
      }
      delay(20);
    }

    while(shoulderC!=0)
    {
      shoulderC = shoulderC - 2;
      backForth.write(shoulderC);
      if(shoulderC<=0)
      {
        shoulderC = 0;
        backForth.write(shoulderC);
      }
      delay(20);
    }

    while(gripD!=0)
    {
      gripD = gripD - 2;
      gripper.write(gripD);
      if(gripD<=0)
      {
        gripD = 0;
        gripper.write(gripD);
      }
      delay(20);
    }
  }
}
