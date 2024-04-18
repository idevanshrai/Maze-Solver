#include <NewPing.h>

#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 200 // in cm :)

#define rightMotor1 5 // Right motor 
#define rightMotor2 6 // Right motor 
#define leftMotor1 10 // Left motor 
#define leftMotor2 9 // Left motor 

#define R 30 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int rightDistance = readDistance(0); 
  int frontDistance = readDistance(90); 

  if (frontDistance > R) {
    moveForward(); //MOVE FORWARD
  } else {
    if (rightDistance > R) {
      turnRight(); //TURNNING RIGHT
    } else {
      turnLeft();  //TURNING LEFT
    }
  }
}

int readDistance(int angle) {
  long duration, cm;
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(angle);
  Serial.print(",");
  Serial.println(cm);
  return cm;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void moveForward() {
  //To move forward
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
}

void turnRight() {
  //To turn right
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  delay(500); 
}

void turnLeft() {
  //To turn left
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  delay(500); 
}
