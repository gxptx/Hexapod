#include <Servo.h>

// Define servo pins for the leg
const int hipPin = 4;
const int kneePin = 2;
const int anklePin = 3;

// Create servo objects for the leg
Servo hipServo;
Servo kneeServo;
Servo ankleServo;

// Define potentiometer pin
const int potPin = A0;

// Define leg length (in whatever unit you're using)
const float legLength = 19.5; // Length of each leg segment in centimeters

void setup() {
  // Attach servos to pins
  hipServo.attach(hipPin);
  kneeServo.attach(kneePin);
  ankleServo.attach(anklePin);
}

void loop() {
  // Read potentiometer value
  int potValue = analogRead(potPin);

  // Map potentiometer value to servo angles
  float angle = map(potValue, 0, 1023, 0, 180);

  // Move all servos to the same angle
  hipServo.write(angle);
  kneeServo.write(angle);
  ankleServo.write(angle);
  
  // Delay for stability
  delay(10); // Adjust delay as needed
}
