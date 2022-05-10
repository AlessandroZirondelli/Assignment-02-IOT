#include "actuators/display/display.h"
#include "Arduino.h"

Display::Display(int address, int width, int height) {
    this->address = address;
    this->lcd = LiquidCrystal_I2C(this->address, width, height);
}

void Display::setup() {
    lcd.init();
    lcd.backlight();
}

void Display::clear() { 
    lcd.clear();
}

void Display::setCursor(int row, int column) { //set the line where the message will be printed
    this->column = column;
    this->row = row;
}

void Display::print(String message) { //print the message
    lcd.setCursor(this->column, this->row);
    lcd.print(message);
}
