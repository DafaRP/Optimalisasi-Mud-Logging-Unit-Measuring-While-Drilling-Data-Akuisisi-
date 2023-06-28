#define RE_DE_PIN 8

struct __attribute__((packed)) packet_data {
  int16_t mapped_pot;
  uint8_t mode;
};

packet_data received;

String topRow = "";
String bottomRow = "0";

void setupComs(uint16_t baud) {
  Serial.begin(baud);
  pinMode(RE_DE_PIN, OUTPUT);
  digitalWrite(RE_DE_PIN, LOW);
}

void getData() {
  if (Serial.available() >= sizeof(packet_data)) {
    Serial.readBytes((byte*)&received, sizeof(packet_data));
    bottomRow = String(received.mapped_pot);
  }
}

void updateAttitude() {
  updateMode();
  updateDisplay();
}

void updateMode() {
  if (received.mode == 0) {
    topRow = "Running LED";
    runningLED();
  } else if (received.mode == 1) {
    topRow = "Blink LED";
    blinkLED();
  } else if (received.mode == 2) {
    animateButterfly();
  } else {
    topRow = "Invalid Mode";  
  }
}

void debugPacket() {
  Serial.print(" Pot: ");
  Serial.print(received.mapped_pot);
  Serial.print(" Mode: ");
  Serial.println(received.mode);
}
