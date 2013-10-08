// #ifndef SettingsScreen_h
// #define SettingsScreen_h

#include <LiquidCrystal.h>

class SettingsScreen {
	public:
		void begin( LiquidCrystal &_lcd );
		void buttonUp( LiquidCrystal &_lcd );
		void buttonDown( LiquidCrystal &_lcd );
		void buttonLeft( LiquidCrystal &_lcd );
		void buttonRight( LiquidCrystal &_lcd );
	private:
		int currentRow;		
		int reps;
		int freq;
		void drawScreen( LiquidCrystal &_lcd );
};

// #endif