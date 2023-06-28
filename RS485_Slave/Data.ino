int16_t LED_PIN[] = {A6, A7, A3, A2, 3, 6, 7, 9};
// A6 A7 A3 A2 D3 D6 D7 D9
const uint8_t NUM_LEDS = 8;
const uint8_t DELAY_TIME = 100;
const uint16_t BLINK_INTERVAL = 500;

unsigned long previousMillis = 0;
unsigned long prevMil[NUM_LEDS];
bool ledState[NUM_LEDS];
int currentLED = 0;

void setupComponent() {
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PIN[i], OUTPUT);
    ledState[i] = false;
  }
}

void runningLED() {
  unsigned long currentMillis = millis();
  // Check if it's time to move to the next LED
  if (currentMillis - previousMillis >= DELAY_TIME) {
    previousMillis = currentMillis;

    // Turn off the current LED
    digitalWrite(LED_PIN[currentLED], LOW);

    // Move to the next LED
    currentLED = (currentLED + 1) % NUM_LEDS;

    // Turn on the next LED
    digitalWrite(LED_PIN[currentLED], HIGH);
  }
}

void blinkLED() {
  for (int i = 0; i < NUM_LEDS; i++) {
    unsigned long currentMillis = millis();
    if (currentMillis - prevMil[i] >= BLINK_INTERVAL) {
      prevMil[i] = currentMillis;
      ledState[i] = !ledState[i];
      digitalWrite(LED_PIN[i], ledState[i] ? HIGH : LOW);
    }
  }
}
