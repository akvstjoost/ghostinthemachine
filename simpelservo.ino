#include <Servo.h>

Servo servo1; 

void setup() {
  servo1.attach(3);  
}

void loop() {
  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
}
