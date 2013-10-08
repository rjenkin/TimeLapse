#include <Arduino.h>
#include <LiquidCrystal.h>
#include "IntroScreen.h"

void IntroScreen::begin( LiquidCrystal &_lcd ) {
	_lcd.noBlink();
	_lcd.clear();
	_lcd.print("Time Lapse");
	_lcd.setCursor(0, 1);
	_lcd.print("Controller");
}

void IntroScreen::buttonUp( LiquidCrystal &_lcd ) {
}

void IntroScreen::buttonDown( LiquidCrystal &_lcd ) {
}

void IntroScreen::buttonLeft( LiquidCrystal &_lcd ) {
}

void IntroScreen::buttonRight( LiquidCrystal &_lcd ) {
}