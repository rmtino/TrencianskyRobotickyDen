/*
 * this class is used to applicate the PID algorhitm
 */


void calculatePID() {
  P = error;
  I += error;
  D = lastError + error;
  lastError = error;
  PID = (P * Kp) + (I * Ki) + (D * Kd);
  if (PID > 255) {
    PID = 255;
  }
}

void PIDMotorControl() {
  calculatePID();

  analogWrite(SPEEDA, baseSpeed - PID);
  analogWrite(SPEEDB, baseSpeed + PID);

  if (error == 0) {
    straight();
  }
  else if (error > 0) {
    turnRight();
  }
  else if (error < 0) {
    turnLeft();
  }
}

