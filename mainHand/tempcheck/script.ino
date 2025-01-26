// Define motor pins for M1 (shoulder motor), M2 (elbow motor), and M3 (hand motor)
const int M1_EN = 3;  // Enable pin for Motor 1 (shoulder)
const int M1_IN1 = 4; // Input 1 for Motor 1
const int M1_IN2 = 5; // Input 2 for Motor 1

const int M2_EN = 6;  // Enable pin for Motor 2 (elbow)
const int M2_IN1 = 7; // Input 1 for Motor 2
const int M2_IN2 = 8; // Input 2 for Motor 2

const int M3_EN = 9;  // Enable pin for Motor 3 (hand)
const int M3_IN1 = 10; // Input 1 for Motor 3
const int M3_IN2 = 11; // Input 2 for Motor 3

void setup() {
  // Set motor pins as outputs
  pinMode(M1_EN, OUTPUT);
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);

  pinMode(M2_EN, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);

  pinMode(M3_EN, OUTPUT);
  pinMode(M3_IN1, OUTPUT);
  pinMode(M3_IN2, OUTPUT);

  // Stop all motors initially
  stopMotor(M1_EN, M1_IN1, M1_IN2);
  stopMotor(M2_EN, M2_IN1, M2_IN2);
  stopMotor(M3_EN, M3_IN1, M3_IN2);
}

void loop() {
  // Call the second function once
  secondFunction();
  delay(10000); // Wait for 10 seconds (or adjust as needed)
}

// Function for coordinated movement (M1 to 95°, M2 to 10°, M3 to 80%)
void secondFunction() {
  int speedM1 = 150; // Speed for shoulder motor (M1)
  int speedM2 = 100; // Speed for elbow motor (M2)
  int speedM3 = 200; // Speed for hand motor (M3)

  int durationM1 = 3000; // Time to move M1 to 95° (adjust based on testing)
  int durationM2 = 1000; // Time to move M2 to 10° (adjust based on testing)
  int durationM3 = 1500; // Time to set M3 to 80% (adjust based on testing)

  // Move M1 (shoulder) to 95°
  analogWrite(M1_EN, speedM1);
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
  delay(durationM1);
  stopMotor(M1_EN, M1_IN1, M1_IN2);

  // Move M2 (elbow) to 10°
  analogWrite(M2_EN, speedM2);
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  delay(durationM2);
  stopMotor(M2_EN, M2_IN1, M2_IN2);

  // Move M3 (hand) to 80%
  analogWrite(M3_EN, speedM3);
  digitalWrite(M3_IN1, HIGH);
  digitalWrite(M3_IN2, LOW);
  delay(durationM3);
  stopMotor(M3_EN, M3_IN1, M3_IN2);

  // Hold the position for 15 seconds
  delay(15000);

  // Return all motors to their normal positions

  // Return M1 (shoulder) to normal
  analogWrite(M1_EN, speedM1);
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  delay(durationM1);
  stopMotor(M1_EN, M1_IN1, M1_IN2);

  // Return M2 (elbow) to normal
  analogWrite(M2_EN, speedM2);
  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);
  delay(durationM2);
  stopMotor(M2_EN, M2_IN1, M2_IN2);

  // Return M3 (hand) to normal
  analogWrite(M3_EN, speedM3);
  digitalWrite(M3_IN1, LOW);
  digitalWrite(M3_IN2, HIGH);
  delay(durationM3);
  stopMotor(M3_EN, M3_IN1, M3_IN2);
}

// Function to stop a motor
void stopMotor(int enPin, int in1Pin, int in2Pin) {
  analogWrite(enPin, 0);
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
}
