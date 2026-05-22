void setup() {

  // Set built-in LED pin as output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // LED ON
  digitalWrite(LED_BUILTIN, HIGH);

  // Wait 1 second
  delay(1000);

  // LED OFF
  digitalWrite(LED_BUILTIN, LOW);

  // Wait 1 second
  delay(1000);
}
