/*
 * This class is used to control motors
 */



void straight() {
  //set the speed of motors to base speed
  analogWrite(SPEEDA, baseSpeed);
  analogWrite(SPEEDB, baseSpeed);
  
  //set direction - go forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight(int speed) {
  //set the speed of motors to parameter speed
  analogWrite(SPEEDA, speed);
  analogWrite(SPEEDB, speed);
  
  //set direction - turn right
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft(int speed) {
  analogWrite(SPEEDA, speed);
  analogWrite(SPEEDB, speed);
  
  //set direction - turn left
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


