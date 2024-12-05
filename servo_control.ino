#include <Servo.h>  // Include the Servo library

// Declare variables for sensor readings
float nw, ne, sw, se;

// Servo angles and state variables
int topangle = 90;  // Initial angle for the top servo
int botangle = 90;  // Initial angle for the bottom servo
bool flipped = false;  // Indicates if the system is flipped
int servo1 = 9;    // PWM pin for the servo
int angle1 = 90;   // Start the servo at 90 degrees (middle position)

// Test angles for debugging purposes
int testangle1 = 0;
int testangle2 = 180;
int startangle = 90;

// Create Servo objects for the top and bottom servos
Servo s1; // Bottom servo
Servo s2; // Top servo

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Starting...");

  // Attach servos to their respective pins
  s1.attach(9); // Bottom servo on pin 9
  s2.attach(8); // Top servo on pin 8

  Serial.println("Setup complete, entering loop...");
}

void loop() {
  // Read voltage from the sensors and scale to 0-5V
  nw = analogRead(A1) * (5.0 / 1023.0);  
  ne = analogRead(A2) * (5.0 / 1023.0);  
  sw = analogRead(A3) * (5.0 / 1023.0);
  se = analogRead(A4) * (5.0 / 1023.0);

  // Variables to hold sums of sensor readings
  float esum, nsum, wsum, ssum, tol;
  tol = 0.2;  // Tolerance threshold for adjustments
  
  // Calculate directional sums
  esum = ne + se;
  wsum = nw + sw;
  nsum = ne + nw;
  ssum = se + sw;

  // Determine if the system is flipped
  flipped = (topangle >= 90) ? false : true;

  // Adjust bottom servo angle based on east-west difference
  if (!flipped) {
    if (esum - wsum < 0 && abs(esum - wsum) > tol) {
      botangle -= 1;
    } else if (esum - wsum > 0 && abs(esum - wsum) > tol) {
      botangle += 1;
    }
  } else {
    if (esum - wsum < 0 && abs(esum - wsum) > tol) {
      botangle += 1;
    } else if (esum - wsum > 0 && abs(esum - wsum) > tol) {
      botangle -= 1;
    }
  }

  // Adjust top servo angle based on north-south difference
  if (nsum - ssum < 0 && abs(nsum - ssum) > tol) {
    topangle += 1;
  } else if (nsum - ssum > 0 && abs(nsum - ssum) > tol) {
    topangle -= 1;
  }

  // Handle flipping behavior when bottom servo angle reaches extreme values
  if (botangle == 180 && abs(esum - wsum) > 0.5) {
    botangle = 10;  // Reset bottom servo angle
    topangle = 180 - topangle;  // Flip top servo
    topangle = constrain(topangle, 0, 180);
    botangle = constrain(botangle, 0, 180);
    s1.write(botangle);
    s2.write(topangle);
    delay(1500);  // Delay to stabilize the system
  } else if (botangle == 0 && abs(esum - wsum) > 0.5) {
    botangle = 170;  // Reset bottom servo angle
    topangle = 185 - topangle;  // Flip top servo
    topangle = constrain(topangle, 0, 180);
    botangle = constrain(botangle, 0, 180);
    s1.write(botangle);
    s2.write(topangle);
    delay(1500);  // Delay to stabilize the system
  }

  // Constrain servo angles to valid ranges
  topangle = constrain(topangle, 0, 180);
  botangle = constrain(botangle, 0, 180);
  
  // Debugging: Print current angles to the Serial Monitor
  Serial.println(topangle);
  Serial.println(botangle);

  // Update servo positions
  s1.write(botangle);
  s2.write(topangle);
  
  delay(5);  // Small delay to smooth out the movements
}