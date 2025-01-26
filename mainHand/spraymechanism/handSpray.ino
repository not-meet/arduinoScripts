// Function to lift the hand (M1 to 95% up)
void liftHand() {
  int speedM1 = 150;      // Speed for shoulder motor (M1)
  int durationLift = 3000; // Time to move M1 to 95% (adjust based on testing)
  
  // Lift M1 to 95% up
  analogWrite(M1_EN, speedM1);
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
  delay(durationLift);
  stopMotor(M1_EN, M1_IN1, M1_IN2);

  // Hold the position for 1 minute
  delay(60000);

  // Return M1 to normal position
  analogWrite(M1_EN, speedM1);
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  delay(durationLift);
  stopMotor(M1_EN, M1_IN1, M1_IN2);
}

void loop() {
  // Call the liftHand function once
  liftHand();
  delay(10000); // Wait 10 seconds before doing anything else (or adjust as needed)
}
