#include <Arduino.h>
#include <LiquidCrystal.h>
#include "StatsScreen.h"

void StatsScreen::begin( LiquidCrystal &_lcd ) {
	drawScreen(_lcd);
	_lcd.noBlink();
}
void StatsScreen::drawScreen( LiquidCrystal &_lcd ) {
	_lcd.clear();

	_lcd.setCursor(0, 0);
	_lcd.print("Taken: ");
	_lcd.print(taken);

	_lcd.setCursor(0, 1);
	_lcd.print("Next: ");
}
void StatsScreen::buttonUp( LiquidCrystal &_lcd ) {
}
void StatsScreen::buttonDown( LiquidCrystal &_lcd ) {
}
void StatsScreen::buttonLeft( LiquidCrystal &_lcd ) {
}
void StatsScreen::buttonRight( LiquidCrystal &_lcd ) {
}
