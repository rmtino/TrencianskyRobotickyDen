//define motor pins
#define IN1 12
#define IN2 9
#define IN3 13
#define IN4 8
#define SPEEDA 3
#define SPEEDB 11

//define sensor pins
int sensorPins[4] = {A3, A2, 5, 6};
int sensorData[4];

//define base speed for motors
int baseSpeed = 220;

//define PID things
int error = 0;
int P, I, D;
int Kp = 1, Ki = 1, Kd = 1;
int PID;
int lastError;


