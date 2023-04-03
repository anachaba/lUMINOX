#include "Arduino.h"
#include <Servo.h>
#include <math.h>

class Ship{
public:
Ship(int servoPin,int motorPin,int sensorPin,int pingPin,int echoPin);

void initial(float x,float y);
void destination(double x,double y);
void tempDestination(double x);
// void speed(long speed);
double getAngle(double x1,double y1);
void go();
void start();
void left(Servo servo);
void right(Servo servo);
void forward(Servo servo);
void Direction(Servo servo,int direction);
void dir(Servo servo,int angle);
void backward();
void halt();
void ultrasonic();
long microsecondsToInches(long microseconds);
long microsecondsToCentimeters(long microseconds);


private:

long duration, inches, cm;
int _servoPin,_motorPin,_sensorPin;
int _pingPin,_echoPin;
float _x;
float _y;
float _toX;
float _toY;
long _speed;
int _angle = 180;
bool _running = false;
Servo _servo;
double coordX;
double coordY;


};
