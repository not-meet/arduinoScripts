// Function to lift M1 (shoulder) to 95% and set M3 (hand) to 90%
void liftHandWithM3() {
  int speedM1 = 150;      // Speed for shoulder motor (M1)
  int speedM3 = 200;      // Speed for hand motor (M3)
  int durationLiftM1 = 3000; // Time to move M1 to 95% (adjust based on testing)
  int durationLiftM3 = 1500; // Time to move M3 to 90% (adjust based on testing)

  // Lift M1 to 95% up
  analogWrite(M1_EN, speedM1);
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
  delay(durationLiftM1);
  stopMotor(M1_EN, M1_IN1, M1_IN2);

  // Move M3 to 90%
  analogWrite(M3_EN, speedM3);
  digitalWrite(M3_IN1, HIGH);
  digitalWrite(M3_IN2, LOW);
  delay(durationLiftM3);
  stopMotor(M3_EN, M3_IN1, M3_IN2);

  // Hold the position for 1 minute
  delay(60000);

  // Return M1 to normal position
  analogWrite(M1_EN, speedM1);
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  delay(durationLiftM1);
  stopMotor(M1_EN, M1_IN1, M1_IN2);

  // Return M3 to normal position
  analogWrite(M3_EN, speedM3);
  digitalWrite(M3_IN1, LOW);
  digitalWrite(M3_IN2, HIGH);
  delay(durationLiftM3);
  stopMotor(M3_EN, M3_IN1, M3_IN2);
}

void loop() {
  // Call the liftHandWithM3 function once
  liftHandWithM3();
  delay(10000); // Wait 10 seconds before calling any other function (or adjust as needed)
}
