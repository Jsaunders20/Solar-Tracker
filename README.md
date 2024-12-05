Dual Servo Light Tracker

Overview

This project implements a dual-servo system designed to track the position of a light source. The system uses four light sensors arranged in quadrants to calculate intensity differences and adjust the servos to maintain alignment with the light source. The code dynamically adjusts the angles of the servos to ensure accurate tracking and stability.

Features

	•	Dual Servo Control: Independently manages a top and bottom servo to align with a light source.
	•	Dynamic Adjustments: Reacts to changes in light intensity using real-time sensor input.
	•	Flip Mechanism: Automatically flips servo orientation when angles reach extreme values.
	•	Tolerance Threshold: Includes a customizable tolerance to avoid unnecessary adjustments.
	•	Debugging Output: Provides detailed logs of servo angles via the Serial Monitor.

Components

	•	Arduino Uno (or compatible board)
	•	Servo Motors (x2): One for horizontal and one for vertical alignment.
	•	Photoresistors or Light Sensors (x4): Arranged in a 2x2 grid for quadrant-based light tracking.
	•	Resistors: Appropriate values for the light sensors.
	•	Power Supply: Ensure sufficient current for servos and sensors.

How It Works

	1.	The light sensors detect intensity in four quadrants: northwest (NW), northeast (NE), southwest (SW), and southeast (SE).
	2.	The system calculates the sum of light intensity for:
	•	East and West (E/W)
	•	North and South (N/S)
	3.	Based on the differences in intensity and a defined tolerance, the servo angles are adjusted to align with the light source.
	4.	If the bottom servo angle exceeds its limits (0° or 180°), the system flips orientation to maintain stability.

Installation

	1.	Clone this repository:
 ```git clone https://github.com/your-username/dual-servo-light-tracker.git```
 
	2.	Open the dual_servo_tracker.ino file in the Arduino IDE.
	3.	Connect your hardware as described in the “Components” section.
	4.	Upload the code to your Arduino board.

Parts List for Solar Tracking System

Core Components
	
 	1. 1x Arduino Uno R3
	2. 2x 180° Servo Motors (5V)
	3. 4x Small Solar Panels (5V)
	4. 1x Breadboard or Protoboard
	5. 1x 9V Battery + Battery Clip
	6. 1x 5V Voltage Regulator

Wiring Components

	1. 22 AWG Wire (Multiple Colors)
  		- Red for power
   		- Black for ground
   		- Various colors for signals
	2. Male-to-Male Jumper Wires
	3. Heat Shrink Tubing (Various Sizes)
	4. Wire Ties for Cable Management

3D Printed Parts (cad_components_fusion360.f3z)
	
	1. Base Housing
	2. Motor Mounting Bracket
	3. Extension Arm
	4. Solar Panel Array Frame
	5. Cable Management Clips

Hardware

	1. Heat-Set Threaded Inserts (M3)
	2. M3 Machine Screws (Various Lengths)
	3. M3 Washers
	4. Servo Mounting Screws

Tools Required

	1. Soldering Iron with Temperature Control
	2. Heat Gun (for heat shrink)
	3. Wire Strippers
	4. Small Phillips Screwdriver
	5. Allen Key Set
	6. Multimeter

Optional/Recommended
	
 	1. Electrical Tape
	2. Strain Relief Clips
	3. Spare Wires and Connectors
	4. Wire Labels
	5. Extra Heat-Set Inserts (for practice)
Usage

	1.	Ensure the light sensors are correctly calibrated for the expected light intensity range.
	2.	Power on the system and observe the servos aligning with the light source.
	3.	Use the Serial Monitor (9600 baud) for debugging and to view servo angles in real-time.

Configuration

	•	Tolerance (tol): Modify this variable in the code to set the sensitivity of adjustments.
	•	Initial Servo Angles: Adjust topangle and botangle for starting positions.

Future Improvements

	•	Add PID control for smoother servo adjustments.
	•	Implement multi-source detection and prioritization.
	•	Optimize the flipping mechanism for faster response times.

License

This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments

Special thanks to the Arduino community for resources and support.
