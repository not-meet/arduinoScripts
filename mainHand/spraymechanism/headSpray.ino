#include <AFMotor.h>

// Create motor instances for M1 (shoulder) and M3 (hand)
AF_DCMotor motor1(1); // M1 is connected to port 1
AF_DCMotor motor3(3); // M3 is connected to port 3

void setup() {
  // Set initial speeds for the motors
  motor1.setSpeed(150); // Speed for shoulder motor (M1)
  motor3.setSpeed(200); // Speed for hand motor (M3)
}

void loop() {
  // Call the liftHandWithM3 function once
  liftHandWithM3();
  delay(10000); // Wait 10 seconds before calling any other function (or adjust as needed)
}

// Function to lift M1 (shoulder) to 95% and set M3 (hand) to 90%
void liftHandWithM3() {
  int durationLiftM1 = 3000; // Time to move M1 to 95% (adjust based on testing)
  int durationLiftM3 = 1500; // Time to move M3 to 90% (adjust based on testing)

  // Lift M1 to 95% up
  motor1.setSpeed(150);   // Set speed for M1
  motor1.run(FORWARD);    // Move M1 forward
  delay(durationLiftM1);  // Wait for M1 to reach 95%
  motor1.run(RELEASE);    // Stop M1

  // Move M3 to 90%
  motor3.setSpeed(200);   // Set speed for M3
  motor3.run(FORWARD);    // Move M3 forward
  delay(durationLiftM3);  // Wait for M3 to reach 90%
  motor3.run(RELEASE);    // Stop M3

  // Hold the position for 1 minute
  delay(60000);

  // Return M1 to normal position
  motor1.setSpeed(150);   // Set speed for M1
  motor1.run(BACKWARD);   // Move M1 backward
  delay(durationLiftM1);  // Wait for M1 to return to normal
  motor1.run(RELEASE);    // Stop M1

  // Return M3 to normal position
  motor3.setSpeed(200);   // Set speed for M3
  motor3.run(BACKWARD);   // Move M3 backward
  delay(durationLiftM3);  // Wait for M3 to return to normal
  motor3.run(RELEASE);    // Stop M3
}
