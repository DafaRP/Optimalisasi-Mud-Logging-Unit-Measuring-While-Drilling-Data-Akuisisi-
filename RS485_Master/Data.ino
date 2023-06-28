#define POT_PIN   A6
#define PB_PIN    9

void setupComponent() {
  pinMode(POT_PIN, INPUT);
  pinMode(PB_PIN, INPUT_PULLUP);
}

void getMappedPot() {
  uint16_t pot_value = analogRead(POT_PIN);
  data.mapped_pot = map(pot_value, 0, 1023, 1, 100);
}

void switchMode() {
  uint8_t is_pressed = digitalRead(PB_PIN);

  if (!is_pressed) {
    if (data.mode >= 3) {
      data.mode = 0;
    } else {
      data.mode += 1;
    }
    delay(500);
  }
}

void updateData() {
  getMappedPot();
  switchMode();
}
