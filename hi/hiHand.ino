// Define motor pins for M4 (elbow motor)
const int M4_EN = 11;  // Enable pin for Motor 4
const int M4_IN1 = 8;  // Input 1 for Motor 4
const int M4_IN2 = 12; // Input 2 for Motor 4

void setup() {
  // Set motor pins as outputs
  pinMode(M4_EN, OUTPUT);
  pinMode(M4_IN1, OUTPUT);
  pinMode(M4_IN2, OUTPUT);

  // Set initial motor states
  stopMotor(M4_EN, M4_IN1, M4_IN2);
}

void loop() {
  // Call the hi function once
  hi();
  delay(5000); // Wait for 5 seconds before repeating (not necessary if it's just one-time use)
}

// Function to simulate the "hi" gesture (move to 160 degrees and return)
void hi() {
  int speed = 100; // Slow speed for smooth movement (range 0-255)
  int duration = 2000; // Duration for the waving motion in milliseconds

  // Move the elbow motor to 160 degrees (raising the arm)
  analogWrite(M4_EN, speed);
  digitalWrite(M4_IN1, HIGH);  // Move the arm in the desired direction
  digitalWrite(M4_IN2, LOW);
  delay(duration); // Keep the motor running to reach 160 degrees

  // Pause at 160 degrees for a moment
  stopMotor(M4_EN, M4_IN1, M4_IN2);
  delay(500); // Pause for 0.5 seconds

  // Move the elbow motor back to the starting position (normal position)
  analogWrite(M4_EN, speed);
  digitalWrite(M4_IN1, LOW);   // Reverse direction to return the arm to the start
  digitalWrite(M4_IN2, HIGH);
  delay(duration); // Keep the motor running to return to the normal position

  // Stop the motor after completing the motion
  stopMotor(M4_EN, M4_IN1, M4_IN2);
}

// Function to stop the motor
void stopMotor(int enPin, int in1Pin, int in2Pin) {
  analogWrite(enPin, 0);
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
}
