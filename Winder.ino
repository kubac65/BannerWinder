#include <AFMotor.h>

AF_Stepper motor(96, 2);

int trigger = A0;
int fwOverride = A1;
int revOverride = A2;

//Steps to do when triggered
int steps = 1000;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigger, INPUT_PULLUP);
  pinMode(fwOverride, INPUT_PULLUP);
  pinMode(revOverride, INPUT_PULLUP);
  digitalWrite(trigger, HIGH);
  digitalWrite(fwOverride, HIGH);
  digitalWrite(revOverride, HIGH);

  motor.setSpeed(100); 
}

void loop() {
  //Forward override
  if(digitalRead(fwOverride) == LOW){
    motor.step(1, FORWARD, SINGLE);
  }
  //Reverse override
  else if(digitalRead(revOverride) == LOW){
    motor.step(1, BACKWARD, SINGLE);
  }
  
  //Trigger
  if(digitalRead(trigger) == LOW){
    motor.step(steps, FORWARD, SINGLE);
  }
  else{
    motor.step(0, FORWARD, SINGLE);
  }
}