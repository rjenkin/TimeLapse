#include <Wire.h>
#include <LiquidCrystal.h>
#include "IntroScreen.h"
#include "SettingsScreen.h"
#include "ModeScreen.h"
#include "StatsScreen.h"




// A0 for analog / buttons
#define PIN_BUTTONS A0 // Up, down, left, right, mode buttons
const uint8_t pinButtons = A0; // Backlight
const uint8_t pinBacklight = 3; // Backlight
#define PIN_RS       8 // Register select
#define PIN_ENABLE   9 // Enable
#define PIN_DATA_4   4
#define PIN_DATA_5   5
#define PIN_DATA_6   6
#define PIN_DATA_7   7


String serialMessage    = "";    // The message received from the user
boolean serialAvailable = false; // Whether a complete message is available for processing

LiquidCrystal _lcd( PIN_RS, PIN_ENABLE, PIN_DATA_4, PIN_DATA_5, PIN_DATA_6, PIN_DATA_7);


IntroScreen    screen1;
SettingsScreen screen2;
ModeScreen     screen3;
StatsScreen    screen4;

int currentScreen = 0;




void setup() {

	Serial.begin(9600);
	
	lcdSetup();
	
	screen1.begin(_lcd);
	
	
	
	Serial.print("pinBacklight: ");
	Serial.println(pinBacklight);
	
	Serial.print("pinButtons: ");
	Serial.println(pinButtons);
	
	Serial.print("PIN_BUTTONS: ");
	Serial.println(PIN_BUTTONS);
	
	Serial.print("A0: ");
	Serial.println(A0);	
	
	
	

} // End of setup()



void loop() {
return;

	if (serialAvailable) {
		Serial.print("Message: ");
		Serial.println(serialMessage);

		//_lcd.print(serialMessage);
		
		if (serialMessage == "mode") {
			currentScreen++;
			if (currentScreen > 3) {
				currentScreen = 0;
			}
			if (currentScreen == 0) {
				screen1.begin(_lcd);
			}
			else if (currentScreen == 1) {
				screen2.begin(_lcd);
			}
			else if (currentScreen == 2) {
				screen3.begin(_lcd);
			}
			else if (currentScreen == 3) {
				screen4.begin(_lcd);
			}
		}
		else if (serialMessage == "left") {
			if (currentScreen == 0) {
				screen1.buttonLeft(_lcd);
			}
			else if (currentScreen == 1) {
				screen2.buttonLeft(_lcd);
			}
			else if (currentScreen == 2) {
				screen3.buttonLeft(_lcd);
			}
			else if (currentScreen == 3) {
				screen4.buttonLeft(_lcd);
			}
		}
		else if (serialMessage == "right") {
			if (currentScreen == 0) {
				screen1.buttonRight(_lcd);
			}
			else if (currentScreen == 1) {
				screen2.buttonRight(_lcd);
			}
			else if (currentScreen == 2) {
				screen3.buttonRight(_lcd);
			}			
			else if (currentScreen == 3) {
				screen4.buttonRight(_lcd);
			}						
		}
		else if (serialMessage == "up") {
			if (currentScreen == 0) {
				screen1.buttonUp(_lcd);
			}
			else if (currentScreen == 1) {
				screen2.buttonUp(_lcd);
			}
			else if (currentScreen == 2) {
				screen3.buttonUp(_lcd);
			}
			else if (currentScreen == 3) {
				screen4.buttonUp(_lcd);
			}			
		}
		else if (serialMessage == "down") {
			if (currentScreen == 0) {
				screen1.buttonDown(_lcd);
			}
			else if (currentScreen == 1) {
				screen2.buttonDown(_lcd);
			}
			else if (currentScreen == 2) {
				screen3.buttonDown(_lcd);
			}			
			else if (currentScreen == 3) {
				screen4.buttonDown(_lcd);
			}						
		}		

		// Reset the message
		serialMessage = "";
		serialAvailable = false;
	}

} // End of loop()






/**
 * A listener for incoming serial input. The
 * script should wait until the message is
 * fully formed before processing. This should
 * prevent incomplete messages coming in.
 */
void serialEvent() {

	while (Serial.available()) {

		char inChar = (char)Serial.read();

		if (inChar != '\n') {
			serialMessage += inChar;
		}
		else {
			//serialMessage.replace("\r", "");
			//serialMessage.replace("\n", "");		
			serialMessage.trim();
			serialAvailable = true;
		}

	}

}

