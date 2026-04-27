// Different based on which board you're using
#define PIN 14

void setup() {
  Serial.begin(9600);
  Serial.println("hello!");

  pinMode(PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN, HIGH);
  Serial.println("LED on");
  delay(1000);
  digitalWrite(PIN, LOW);
  Serial.println("LED off");
  delay(1000);
}