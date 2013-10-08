// #ifndef IntroScreen_h
// #define IntroScreen_h

#include <LiquidCrystal.h>

class IntroScreen {
	public:
		void begin( LiquidCrystal &_lcd );
		void buttonUp( LiquidCrystal &_lcd );
		void buttonDown( LiquidCrystal &_lcd );
		void buttonLeft( LiquidCrystal &_lcd );
		void buttonRight( LiquidCrystal &_lcd );
};

// #endif