#include <Arduino.h>
#include <LiquidCrystal.h>
#include "SettingsScreen.h"

void SettingsScreen::begin( LiquidCrystal &_lcd ) {
	if (freq == 0) {
		freq = 1;
	}
	drawScreen(_lcd);
	_lcd.setCursor(6, 0);
	_lcd.blink();
}
void SettingsScreen::drawScreen( LiquidCrystal &_lcd ) {
	_lcd.clear();

	_lcd.setCursor(0, 0);
	_lcd.print("Reps: ");
	if (reps > 0) {
		_lcd.print(reps);
	}
	else {
		_lcd.print("inf");
	}
	_lcd.print(" shots");

	_lcd.setCursor(0, 1);
	_lcd.print("Freq: ");
	_lcd.print(freq);
	_lcd.print(" sec");
}

void SettingsScreen::buttonLeft( LiquidCrystal &_lcd ) {
	if (currentRow == 0) {
		Serial.println("SettingsScreen::buttonUp: 0");	
		if (reps > 0) {
			reps--;
		}
		drawScreen(_lcd);
		_lcd.setCursor(6, 0);
	}
	else if (currentRow == 1) {
		Serial.println("SettingsScreen::buttonUp: 1");
		if (freq > 1) {
			freq--;
		}
		drawScreen(_lcd);
		_lcd.setCursor(6, 1);
	}
}

void SettingsScreen::buttonRight( LiquidCrystal &_lcd ) {
	if (currentRow == 0) {
		Serial.println("SettingsScreen::buttonUp: 0");	
		reps++;
		drawScreen(_lcd);
		_lcd.setCursor(6, 0);
	}
	else if (currentRow == 1) {
		Serial.println("SettingsScreen::buttonUp: 1");
		freq++;
		drawScreen(_lcd);
		_lcd.setCursor(6, 1);
	}
}

void SettingsScreen::buttonUp( LiquidCrystal &_lcd ) {
	currentRow++;
	if (currentRow > 1) {
		currentRow = 0;
	}
	if (currentRow == 0) {
		Serial.println("SettingsScreen::buttonLeft: 0");
		_lcd.setCursor(6, 0);
	}
	else if (currentRow == 1) {
		Serial.println("SettingsScreen::buttonLeft: 1");
		_lcd.setCursor(6, 1);
	}
}

void SettingsScreen::buttonDown( LiquidCrystal &_lcd ) {
	buttonUp(_lcd);
}
