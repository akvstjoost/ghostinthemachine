// ** THIS IS A DRAFT - CODE NOT WORKING 

//template by Thomas Rutgers - Techlab St. Joost School of Art & Design

#include <Servo.h>
Servo servo1;
Servo servo2;
int servosLastPos = [0,0];
int motorsLastPWM = [0,0];
int motorPins = [9,10,11,12];

void setup() {
  servo1.attach(3);
  servo2.attach(4);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  digitalWrite(5, LOW);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  //schrijf hier je code
  moveServos(0, 0, 1000);
  moveServos(180, 180, 1000);
  accelMotor(2, 0, 100);
}



void moveServos(int servo1NewPos, int servo2NewPos, int time) { 
  int loops = time / 20;
  if (loops < 1) loops = 1;
  for (int l = 0; l < loops; l++) {
    servo1.write(calcPos(l, loops, servosLastPos[0], servo1NewPos));
    servo2.write(calcPos(l, loops, servosLastPos[1], servo2NewPos));
    delay(20);
    do {
    } while (digitalRead(6) == LOW);

  }
  servosLastPos[0] = servo1NewPos;
  servosLastPos[1] = servo2NewPos;
}

void accelMotor(int motorNr, float percentage, int time) {
  int motorIndex = motorNr - 1 ;
  int motorNewPWM = constrain(precentage * 2.55,-255,255);  
  int loops = time / 20;  if (loops < 1) loops = 1;
  for (int l = 0; l < loops; l++) {
    
    if(speed>0) {
      digitalWrite(motorPin[motorIndex], LOW);
      analogWrite(motorPin[motorIndex+1], calcPos(l, loops, motorLastPWM[motorIndex], motorNewPWM));
    } else {
      digitalWrite(motorPin[motorIndex+1], LOW);
      analogWrite(motorPin[motorIndex], calcPos(l, loops, motorLastPWM[motorIndex], motorNewPWM));      
    }
    delay(20);
    do {
    } while (digitalRead(6) == LOW);

  }
  motorLastPWM[motorIndex] = motorNewPWM;
}

int calcPos(float loop, float loops, float start, float end) {
  return int(end * (loop / loops)) + (start * (1 - (loop / loops)));
}


