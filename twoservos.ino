
#include <Servo.h>
Servo servo1;
Servo servo2;
int _pos1 = 0;
int _pos2 = 0;

void setup() {
  servo1.attach(3);
  servo2.attach(4);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  digitalWrite(5, LOW);
}

void loop() {
  //schrijf hier je code
  moveServos(0, 0, 1000);
  moveServos(180, 180, 1000);

}



void moveServos(int pos1, int pos2, int time) {
  int loops = time / 20;
  if (loops < 1) loops = 1;
  int start1 = _pos1;
  int start2 = _pos2;
  int stop1 = pos1;
  int stop2 = pos2;
  for (int l = 0; l < loops; l++) {
    servo1.write(calcPos(l, loops, start1, stop1));
    servo2.write(calcPos(l, loops, start2, stop2));
    delay(20);
    do {
    } while (digitalRead(12) == LOW);

  }
  _pos1 = pos1;
  _pos2 = pos2;
}

int calcPos(float loop, float loops, float start, float end) {
  return int(end * (loop / loops)) + (start * (1 - (loop / loops)));
}
