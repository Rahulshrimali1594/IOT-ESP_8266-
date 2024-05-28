#define ENA D5
#define IN1 D1
#define IN2 D2
#define ENB D6
#define IN3 D3
#define IN4 D4

#define sensorLeft D7
#define sensorRight D8

void setup() {
  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Sensor pins
  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);
  
  // Initialize motors to stop
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {
  int leftState = digitalRead(sensorLeft);
  int rightState = digitalRead(sensorRight);

  if (leftState == LOW && rightState == LOW) {
    // Move forward
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
    analogWrite(ENB, 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else if (leftState == HIGH && rightState == LOW) {
    // Turn right
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    
    analogWrite(ENB, 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else if (leftState == LOW && rightState == HIGH) {
    // Turn left
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
    analogWrite(ENB, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else {
    // Stop
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    
    analogWrite(ENB, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
