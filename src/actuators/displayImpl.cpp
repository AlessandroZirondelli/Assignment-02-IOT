#include "display.h"
#include "Arduino.h"

display::displayImpl(int address, int width, int height) {
    this->address = address;
    this->lcd = LiquidCrystal_I2C(this->address, width, height);
}

void display::setup() {
    lcd.init();
    lcd.backlight();
}

void display::clear() {
    lcd.clear();
}

void display::selectLine(int row, int column) {
    this->column = column;
    this->row = row;
}

void display::print(String message) {
    lcd.setCursor(this->column, this->row);
    lcd.print(message);
}
