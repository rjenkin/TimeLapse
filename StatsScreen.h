// #ifndef StatsScreen_h
// #define StatsScreen_h

#include <LiquidCrystal.h>

// Stats
// Taken: 1,2,3
// Next: 10sec
class StatsScreen {
	public:
		void begin( LiquidCrystal &_lcd );
		void buttonUp( LiquidCrystal &_lcd );
		void buttonDown( LiquidCrystal &_lcd );
		void buttonLeft( LiquidCrystal &_lcd );
		void buttonRight( LiquidCrystal &_lcd );
	private:
		int currentRow;		
		int taken;
		//int freq;
		void drawScreen( LiquidCrystal &_lcd );
};

// #endif