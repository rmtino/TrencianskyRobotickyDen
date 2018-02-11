/**
 * TRD - Follower hard
 * this is a program for PD controller used for line follower to TRD robotical competition
 * Developer: MartinLinux
 * 
 * tutorial is on Github Wiki
 * This code is open-source - you can download, use and modify it :)
 */

#define LEFTFORWARD 12
#define LEFTBACK 9
#define RIGHTFORWARD 13
#define RIGHTBACK 8

#define SPEEDL 3
#define SPEEDR 11

const int sensors[4] = {A3, A2, 5, 6};
int sensorData[4];

const int baseSpeed = 130;
const int kP = 12, kD = 12;
int P, D, PDValue;
int error;


void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(sensors[i], INPUT);
  }

  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTBACK, OUTPUT);
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTBACK, OUTPUT);

  pinMode(SPEEDL, OUTPUT);
  pinMode(SPEEDR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  readSensors();
  calcError();
  calcPD();
  analogWrite(SPEEDL, baseSpeed - PDValue);
  analogWrite(SPEEDR, baseSpeed + PDValue);
  if (error == 0) {
    digitalWrite(LEFTFORWARD, HIGH);
    digitalWrite(LEFTBACK, LOW);
    digitalWrite(RIGHTFORWARD, HIGH);
    digitalWrite(RIGHTBACK, LOW);
  }
  else if (error > 0) {
    digitalWrite(LEFTFORWARD, LOW);
    digitalWrite(LEFTBACK, LOW);
    digitalWrite(RIGHTFORWARD, HIGH);
    digitalWrite(RIGHTBACK, LOW);
  }
  else if (error < 0) {
    digitalWrite(LEFTFORWARD, HIGH);
    digitalWrite(LEFTBACK, LOW);
    digitalWrite(RIGHTFORWARD, LOW);
    digitalWrite(RIGHTBACK, LOW);
  }
}

void readSensors() {
  for (int i = 0; i < 4; i++) {
    sensorData[i] = digitalRead(sensors[i]);
  }
}

void calcError() {
  if (sensorData[0] == 0 and sensorData[1] == 0 and sensorData[2] == 1 and sensorData[3] == 1) {
    error = 0;
  }
  if (sensorData[0] == 0 and sensorData[1] == 1 and sensorData[2] == 1 and sensorData[3] == 1) {
    error = 1;
  }
  if (sensorData[0] == 1 and sensorData[1] == 1 and sensorData[2] == 1 and sensorData[3] == 1) {
    error = 2;
  }
  if (sensorData[0] == 0 and sensorData[1] == 0 and sensorData[2] == 0 and sensorData[3] == 1) {
    error = -1;
  }
  if (sensorData[0] == 0 and sensorData[1] == 0 and sensorData[2] == 0 and sensorData[3] == 0) {
    error = -2;
  }
}

void calcPD() {
  int lastError; 
  P = error;
  D = error - lastError;
  lastError = error;

  PDValue = P * kP + D *kD;
}

