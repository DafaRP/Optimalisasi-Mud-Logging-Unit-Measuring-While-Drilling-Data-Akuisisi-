#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  setupComs(9600);
  setupComponent();
  setupDisplay();
}

void loop() {
  getData();
  updateAttitude();
//  debugPacket();
}
