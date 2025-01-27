#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  // Set up the trigger pin as an output
  pinMode(TRIG_PIN, OUTPUT);
  // Set up the echo pin as an input
  pinMode(ECHO_PIN, INPUT);
  
  // Initialize the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Measure the duration of the pulse received at the echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance in cm (speed of sound = 34300 cm/s)
  float distance = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Add a small delay before the next reading
  delay(500);
}
