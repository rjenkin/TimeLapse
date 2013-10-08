// #ifndef ModeScreen_h
// #define ModeScreen_h

#include <LiquidCrystal.h>

class ModeScreen {
	public:
		void begin( LiquidCrystal &_lcd );
		void buttonUp( LiquidCrystal &_lcd );
		void buttonDown( LiquidCrystal &_lcd );
		void buttonLeft( LiquidCrystal &_lcd );
		void buttonRight( LiquidCrystal &_lcd );
	private:
		int currentRow;		
		int mode;
		void drawScreen( LiquidCrystal &_lcd );
};

// #endif