#define TOUCH_PIN T0
#define R_PIN 12
#define G_PIN 14
#define B_PIN 27

#define RED 0
#define GREEN 212
#define BLUE 255

int threshold = 700; //might differ board to board

float brightness = 0.0;
float fadeSpeed = 0.05;
void setup() {
  Serial.begin(115200);
  pinMode(T0, INPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  ledcAttach(R_PIN, 5000, 8);
  ledcAttach(G_PIN, 5000, 8);
  ledcAttach(B_PIN, 5000, 8);

  setBaseline();
}

void loop() {
  int touchValue = touchRead(TOUCH_PIN);

  // Serial.println(touchValue);

  if (touchValue < (threshold - threshold/2.5) && touchValue > (threshold - threshold / 1.5)) {
    brightness += fadeSpeed;
    if(brightness > 1.0) brightness = 1.0;
  } else {
    brightness -= fadeSpeed;
    if (brightness < 0.0) brightness = 0.0;
  }
    ledcWrite(R_PIN, (int)(RED * brightness));
    ledcWrite(G_PIN, (int)(GREEN * brightness));
    ledcWrite(B_PIN, (int)(BLUE * brightness));

  delay(10);
}

void setBaseline(){
  int total = 0;
  for (int i = 0; i < 5; i++){
    total += touchRead(TOUCH_PIN);
  }
  threshold = total/5;
  Serial.println(threshold);
}
