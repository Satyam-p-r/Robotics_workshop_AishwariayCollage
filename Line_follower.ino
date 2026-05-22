#define LEFT_SENSOR 2
#define RIGHT_SENSOR 3

// Motor A
#define IN1 8
#define IN2 9

// Motor B
#define IN3 10
#define IN4 11

void setup() {

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int left = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  Serial.print("Left: ");
  Serial.print(left);
  Serial.print(" Right: ");
  Serial.println(right);

  // BOTH WHITE → FORWARD
  if (left == HIGH && right == HIGH) {
    forward();
  }

  // LEFT BLACK → TURN LEFT
  else if (left == LOW && right == HIGH) {
    leftTurn();
  }

  // RIGHT BLACK → TURN RIGHT
  else if (left == HIGH && right == LOW) {
    rightTurn();
  }

  // BOTH BLACK → STOP
  else {
    stopRobot();
  }
}

// ================= MOTOR FUNCTIONS =================

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void leftTurn() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightTurn() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
