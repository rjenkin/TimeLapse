#include <Arduino.h>
#include <LiquidCrystal.h>
#include "ModeScreen.h"

void ModeScreen::begin( LiquidCrystal &_lcd ) {
	drawScreen(_lcd);
	_lcd.blink();
}

void ModeScreen::drawScreen( LiquidCrystal &_lcd ) {
	_lcd.clear();
	_lcd.setCursor(0, 0);
	_lcd.print("Mode: ");
	if (mode == 0) {
		_lcd.print("Finished");
	}
	else if (mode == 1) {
		_lcd.print("Running");
	}
	else if (mode == 2) {
		_lcd.print("Paused");
	}
}

void ModeScreen::buttonUp( LiquidCrystal &_lcd ) {
}

void ModeScreen::buttonDown( LiquidCrystal &_lcd ) {
}

void ModeScreen::buttonLeft( LiquidCrystal &_lcd ) {
	mode++;
	if (mode > 2) {
		mode = 0;
	}
	drawScreen(_lcd);
}

void ModeScreen::buttonRight( LiquidCrystal &_lcd ) {
	buttonLeft(_lcd);
}
