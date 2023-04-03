#include "Ship.h"
#include <Servo.h>

Ship::Ship(int servoPin,int motorPin,int sensorPin,int pingPin,int echoPin){
    _servoPin = servoPin;

    Servo myServo;
    _servo = myServo;

    _servo.attach(_servoPin);

    _pingPin = pingPin;
    pinMode(_pingPin, OUTPUT);
    _echoPin = echoPin;
    pinMode(_echoPin, INPUT);

    _motorPin = motorPin;
    _sensorPin = sensorPin;
    pinMode(sensorPin,OUTPUT);
    pinMode(motorPin,OUTPUT);
    pinMode(sensorPin,OUTPUT);
    

}

void Ship::Direction(Servo myservo,int servo){
    _servoPin = servo;
    myservo.attach(_servoPin);
    
}

void Ship::dir(Servo myservo,int angle){
    myservo.write(angle);
}


void Ship::ultrasonic(){
    

//    pinMode(_pingPinn, OUTPUT);
   digitalWrite(_pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(_pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(_pingPin, LOW);
//    pinMode(_echoPin, INPUT);
   duration = pulseIn(_echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
//    Serial.print(inches);
//    Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);

}

long Ship::microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long Ship::microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}


void Ship::initial(float x = 0.0 ,float y = 0.0){
    _x = x;
    _y = y;
}


double Ship:: getAngle(double x1,double y1){

double dx = x1;
double dy = y1;
double angle = atan2(dy,dx);
angle = angle * 180 / M_PI;
return angle;
}

// void Ship::speed(int speed){
//     _speed = speed;
// }


void Ship::go(){
    ultrasonic();
    //destination(gX,gY);
    if(cm<30){
        
        halt();
        delay(1000);
        left(_servo);
        start();
    }else{
        forward(_servo);
        start();
        
    }
    
}
void Ship:: destination(double x,double y){

double angle = getAngle(x,y);
 _servo.write(angle);
 delay(2000);
  _servo.write(0);
}

void Ship:: tempDestination(double x){


 _servo.write(x);
 delay(2000);
  _servo.write(0);
  delay(2000);
}

void Ship::start(){
_running = true;
    _speed = HIGH;

    digitalWrite(_motorPin, _speed);
    delay(20);
}


void Ship::halt(){
    _running = false;
    _speed = LOW;
    
    analogWrite(_motorPin, _speed);
    delay(20);
    
}



void Ship::left(Servo myservo){
    myservo.write(0);
    delay(500);
}

void Ship::right(Servo myservo){
    myservo.write(150);

}


void Ship::forward(Servo myservo){
    myservo.write(180);
    delay(500);
}


void Ship::backward(){
    halt();

    _running == true;
    while(_running == true){
        analogWrite(_motorPin, -_speed);

}
}
