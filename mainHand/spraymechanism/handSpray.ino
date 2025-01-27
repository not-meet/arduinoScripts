#include <AFMotor.h>

// Create an instance of AF_DCMotor for M1 (shoulder motor)
AF_DCMotor motor1(1); // M1 is connected to port 1 on the motor shield

void setup() {
  // Set the initial speed for the motor
  motor1.setSpeed(150); // Adjust speed (0-255)
}

void loop() {
  // Call the liftHand function once
  liftHand();
  delay(10000); // Wait 10 seconds before doing anything else (or adjust as needed)
}

// Function to lift the hand (M1 to 95% up and back to normal)
void liftHand() {
  int durationLift = 3000; // Time to move M1 to 95% (adjust based on testing)

  // Lift M1 to 95% up
  motor1.setSpeed(150); // Set motor speed
  motor1.run(FORWARD);  // Move motor forward
  delay(durationLift);  // Wait for the motor to reach the position
  motor1.run(RELEASE);  // Stop the motor

  // Hold the position for 1 minute
  delay(60000);

  // Return M1 to normal position
  motor1.setSpeed(150); // Set motor speed
  motor1.run(BACKWARD); // Move motor backward
  delay(durationLift);  // Wait for the motor to return to the start position
  motor1.run(RELEASE);  // Stop the motor
}
