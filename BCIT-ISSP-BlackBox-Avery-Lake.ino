#define TOUCH_PIN T0
#define R_PIN 23
#define B_PIN 21
#define G_PIN 22

#define RED 0
#define GREEN 212
#define BLUE 255

int threshold = 30; // might differ board to board

void setup() {
  Serial.begin(115200);
  ledcAttach(R_PIN, 5000, 8);
  ledcAttach(G_PIN, 5000, 8);
  ledcAttach(B_PIN, 5000, 8);
}

void loop() {
  int touchValue = touchRead(TOUCH_PIN);

  Serial.println(touchValue);

  if (touchValue < threshold) {
    ledcWrite(R_PIN,
              255 -
                  RED); // may not need to subtract depending on type of rgb led
    ledcWrite(G_PIN, 255 - GREEN);
    ledcWrite(B_PIN, 255 - BLUE);
  } else {
    ledcWrite(R_PIN, 255); // off state, may be 0 depending on led
    ledcWrite(G_PIN, 255);
    ledcWrite(B_PIN, 255);
  }

  delay(50);
}