// Control pins for Driver Chip #1 (Motor 1 & Motor 2)
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

// Control pins for Driver Chip #2 (Motor 3 & Motor 4)
int in5 = 6;
int in6 = 7;
int in7 = 8;
int in8 = 9;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
}

void forward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH); digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH); digitalWrite(in8, LOW);
}

void backward() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW); digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW); digitalWrite(in8, HIGH);
}

void turnRight() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
  digitalWrite(in5, HIGH); digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);  digitalWrite(in8, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);  digitalWrite(in6, HIGH);
  digitalWrite(in7, HIGH); digitalWrite(in8, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  digitalWrite(in5, LOW); digitalWrite(in6, LOW);
  digitalWrite(in7, LOW); digitalWrite(in8, LOW);
}

void loop() {
  // 1. Forward for 30 seconds
  forward();
  delay(30000);

  // 2. Backward for a full minute (60 seconds)
  backward();
  delay(60000);

  // 3. Alternate right/left for one minute
  unsigned long turnStart = millis();
  while (millis() - turnStart < 60000) {
    turnRight();
    delay(1000);
    turnLeft();
    delay(1000);
  }

  stopMotors();
  while (true) {
    // Final stop after completing all movements
  }
}