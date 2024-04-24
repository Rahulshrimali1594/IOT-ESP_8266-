const int raindropPin = D1;

void setup() 
{
  // Initialize serial communication
  Serial.begin(115200);
  // Set the raindrop sensor pin as input
  pinMode(raindropPin, INPUT);
}

void loop() {
  // Read the value from the raindrop sensor
  int raindropValue = digitalRead(raindropPin);

  // If raindrop is detected (sensor output is LOW), print a message
  if (raindropValue == LOW) 
  {
    Serial.println("Rain detected!");
  }else 
  {
    Serial.println("Rain is not Detected");
  }
  // Delay before reading again
  delay(1000);
}