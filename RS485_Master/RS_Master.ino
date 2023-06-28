#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  setupComs(9600);
  setupComponent();
  setupDisplay();
  delay(1000);
}

void loop() {
  sendData();
  updateData();
  updateDisplay();
//  debugPacket();
}
