
void lcdSetup() {

	// Button ADC input
	pinMode(A0, INPUT);
	digitalWrite(A0, LOW);

	// LCD backlight control
	pinMode(pinBacklight, OUTPUT);
	digitalWrite(pinBacklight, HIGH);

	// Set up the LCD number of columns and rows: 
	_lcd.begin(16, 2);
}

