/*
 * Arduino Sketch for Robot Car Control by Joystick Remote using Bluetooth
 * This code reads the joystick inputs and sends them via Bluetooth to control
 * the motors of the robot car.
 */

// Define pin connections for joystick
const int joyXPin = A0; // Joystick X-axis
const int joyYPin = A1; // Joystick Y-axis

// Define pin connections for motor control
const int motorLeftPin = 9;  // Left motor PWM pin
const int motorRightPin = 10; // Right motor PWM pin

// Define pin connections for Bluetooth module
const int btTxPin = 2; // Bluetooth TX pin
const int btRxPin = 3; // Bluetooth RX pin

void setup() {
  // Initialize serial communication for Bluetooth
  Serial.begin(9600);
  
  // Set motor pins as output
  pinMode(motorLeftPin, OUTPUT);
  pinMode(motorRightPin, OUTPUT);
  
  // Set Bluetooth pins
  pinMode(btTxPin, OUTPUT);
  pinMode(btRxPin, INPUT);
}

void loop() {
  // Read joystick values
  int joyX = analogRead(joyXPin);
  int joyY = analogRead(joyYPin);
  
  // Map joystick values to motor speed
  int motorLeftSpeed = map(joyY, 0, 1023, -255, 255);
  int motorRightSpeed = map(joyX, 0, 1023, -255, 255);
  
  // Send joystick values via Bluetooth
  Serial.print("X:");
  Serial.print(joyX);
  Serial.print(" Y:");
  Serial.println(joyY);
  
  // Control motors
  analogWrite(motorLeftPin, constrain(motorLeftSpeed, 0, 255));
  analogWrite(motorRightPin, constrain(motorRightSpeed, 0, 255));
  
  // Small delay to stabilize readings
  delay(100);
}
