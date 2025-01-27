#include <AFMotor.h>

// Create an instance of AF_DCMotor for M4 (elbow motor)
AF_DCMotor motor4(4); // M4 is connected to port 4 on the motor shield

void setup() {
  // Set initial motor state
  motor4.setSpeed(100); // Set initial speed (0-255)
}

void loop() {
  // Call the hi function once
  hi();
  delay(5000); // Wait for 5 seconds before repeating (not necessary for one-time use)
}

// Function to simulate the "hi" gesture (move to 160 degrees and return)
void hi() {
  int speed = 100;    // Slow speed for smooth movement (range 0-255)
  int duration = 2000; // Duration for the waving motion in milliseconds

  // Move the elbow motor to 160 degrees (raising the arm)
  motor4.setSpeed(speed);
  motor4.run(FORWARD); // Move the motor forward
  delay(duration);     // Keep the motor running for the desired duration

  // Pause at 160 degrees for a moment
  motor4.run(RELEASE); // Stop the motor
  delay(500);          // Pause for 0.5 seconds

  // Move the elbow motor back to the starting position (normal position)
  motor4.run(BACKWARD); // Reverse the motor direction
  delay(duration);      // Keep the motor running to return to the normal position

  // Stop the motor after completing the motion
  motor4.run(RELEASE);
}
