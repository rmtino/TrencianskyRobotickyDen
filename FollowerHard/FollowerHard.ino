/*
 * This is PID line follower project for robotical competition Trenciansky Roboticky Den
 * category is follower hard
 * creator: MartinLinux
 * this code is open-source: you can download, use and modify it:)
 */

#include "define.h"

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(SPEEDA, OUTPUT);
  pinMode(SPEEDB, OUTPUT);
}

void loop() {
  readSensors();
  
}
