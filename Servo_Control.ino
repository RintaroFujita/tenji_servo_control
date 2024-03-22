#include <Servo.h>

Servo myServo;
int initialPosition = 50;
int targetPosition = 20;
int delayTime = 2000;
unsigned long lastMoveTime = 0;
unsigned long interval = 15000;

void setup() {
  myServo.attach(9);
  myServo.write(initialPosition);
  delay(1000);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastMoveTime >= interval) {
    moveServo();
    lastMoveTime = currentTime;
  }
}

void moveServo() {
  myServo.write(targetPosition);
  delay(delayTime);
  myServo.write(initialPosition);
  delay(delayTime);
}
