# **Circuit Documentation**

## **Summary**

This circuit is designed to control a robot car using a joystick remote interface and Bluetooth communication. The core of the circuit is an Arduino Mega 2560 microcontroller, which reads inputs from a KY-023 Dual Axis Joystick Module and sends control signals to two hobby gearmotors. The Arduino also interfaces with an HC-05 Bluetooth Module to enable wireless communication. The joystick provides directional input, which is then translated into motor control signals to drive the robot car.

## **Component List**

### **Arduino Mega 2560**

* Microcontroller board based on the ATmega2560  
* It has 54 digital input/output pins (of which 15 can be used as PWM outputs), 16 analog inputs, 4 UARTs (hardware serial ports), a 16 MHz crystal oscillator, a USB connection, a power jack, an ICSP header, and a reset button.

### **KY-023 Dual Axis Joystick Module**

* A module that provides a two-axis thumb joystick  
* It has a comfortable cup-type knob that can be moved in two dimensions for X and Y axis control, and it includes a pushbutton when pressed down.

### **HC-05 Bluetooth Module**

* A wireless communication module that can be used in master or slave configuration  
* It allows the Arduino to communicate with other Bluetooth-enabled devices like smartphones or computers.

### **Hobby Gearmotor with 48:1 Gearbox (2 units)**

* A small DC motor with a gearbox for increased torque  
* It is typically used in robotics applications for driving wheels or other moving parts.

## **Wiring Details**

### **KY-023 Dual Axis Joystick Module**

* VRx connected to A0 on Arduino Mega 2560  
* VRy connected to A1 on Arduino Mega 2560  
* \+5V connected to 5V on Arduino Mega 2560  
* GND connected to GND on Arduino Mega 2560

### **HC-05 Bluetooth Module**

* VCC connected to 5V on Arduino Mega 2560  
* TXD connected to D2 PWM on Arduino Mega 2560  
* RXD connected to D3 PWM on Arduino Mega 2560  
* GND connected to GND on Arduino Mega 2560

### **Hobby Gearmotor with 48:1 Gearbox (Motor 1\)**

* pin 1 connected to D9 PWM on Arduino Mega 2560  
* pin 2 connected to GND on Arduino Mega 2560

### **Hobby Gearmotor with 48:1 Gearbox (Motor 2\)**

* pin 1 connected to D10 PWM on Arduino Mega 2560  
* pin 2 connected to GND on Arduino Mega 2560

## **Documented Code**

`/*`  
 `* Arduino Sketch for Robot Car Control by Joystick Remote using Bluetooth`  
 `* This code reads the joystick inputs and sends them via Bluetooth to control`  
 `* the motors of the robot car.`  
 `*/`

`// Define pin connections for joystick`  
`const int joyXPin = A0; // Joystick X-axis`  
`const int joyYPin = A1; // Joystick Y-axis`

`// Define pin connections for motor control`  
`const int motorLeftPin = 9;  // Left motor PWM pin`  
`const int motorRightPin = 10; // Right motor PWM pin`

`// Define pin connections for Bluetooth module`  
`const int btTxPin = 2; // Bluetooth TX pin`  
`const int btRxPin = 3; // Bluetooth RX pin`

`void setup() {`  
  `// Initialize serial communication for Bluetooth`  
  `Serial.begin(9600);`  
    
  `// Set motor pins as output`  
  `pinMode(motorLeftPin, OUTPUT);`  
  `pinMode(motorRightPin, OUTPUT);`  
    
  `// Set Bluetooth pins`  
  `pinMode(btTxPin, OUTPUT);`  
  `pinMode(btRxPin, INPUT);`  
`}`

`void loop() {`  
  `// Read joystick values`  
  `int joyX = analogRead(joyXPin);`  
  `int joyY = analogRead(joyYPin);`  
    
  `// Map joystick values to motor speed`  
  `int motorLeftSpeed = map(joyY, 0, 1023, -255, 255);`  
  `int motorRightSpeed = map(joyX, 0, 1023, -255, 255);`  
    
  `// Send joystick values via Bluetooth`  
  `Serial.print("X:");`  
  `Serial.print(joyX);`  
  `Serial.print(" Y:");`  
  `Serial.println(joyY);`  
    
  `// Control motors`  
  `analogWrite(motorLeftPin, constrain(motorLeftSpeed, 0, 255));`  
  `analogWrite(motorRightPin, constrain(motorRightSpeed, 0, 255));`  
    
  `// Small delay to stabilize readings`  
  `delay(100);`  
`}`

This code is designed to be uploaded to the Arduino Mega 2560\. It initializes the joystick and motor pins, reads the joystick inputs, maps them to motor speeds, and sends the values via Bluetooth. It also controls the motors based on the joystick inputs.
