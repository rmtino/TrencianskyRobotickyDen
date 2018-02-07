/*
 * This class is used to read IR sensors and calculate error for PID controller
 */



void readSensors() {
  //reading data with for loop
  for (int i = 0; i <4; i++) {
    sensorData[i] = digitalRead(sensorPins[i]);
  }
}

void calcError() {
  if (sensorData[0] == 0 && sensorData[1] == 0 && sensorData[2] == 1 && sensorData[3] == 1) {
    error = 0;
  }
  if (sensorData[0] == 0 && sensorData[1] == 1 && sensorData[2] == 1 && sensorData[3] == 1) {
    error = 1;
  }
  if (sensorData[0] == 1 && sensorData[1] == 1 && sensorData[2] == 1 && sensorData[3] == 1) {
    error = 2;
  }
  if (sensorData[0] == 0 && sensorData[1] == 0 && sensorData[2] == 0 && sensorData[3] == 1) {
    error = -1;
  }
  if (sensorData[0] == 0 && sensorData[1] == 0 && sensorData[2] == 0 && sensorData[3] == 0) {
    error = -2;
  }
}

