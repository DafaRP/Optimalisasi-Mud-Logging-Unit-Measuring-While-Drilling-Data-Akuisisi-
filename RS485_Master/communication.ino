#define RE_DE_PIN 8

struct __attribute__((packed)) packet_data {
  int16_t mapped_pot;
  uint8_t mode;
};

packet_data data = {0, 0};

String topRow = "";
String bottomRow = "";

void setupComs(uint16_t baud) {
  Serial.begin(baud);
  pinMode(RE_DE_PIN, OUTPUT);
  digitalWrite(RE_DE_PIN, HIGH);
}

void sendData() {
  Serial.write((const byte*)&data, sizeof(data));
  topRow = String(data.mode);
  bottomRow = String(data.mapped_pot);
}

void debugPacket() {
  Serial.print(" Pot: ");
  Serial.print(data.mapped_pot);
  Serial.print(" Mode: ");
  Serial.println(data.mode);
}
