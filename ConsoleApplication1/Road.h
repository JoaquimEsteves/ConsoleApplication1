#pragma once
#include "StaticObject.h"
#include "Cheerio.h"
#define CHEERIOS_NUMBER 100

class Road : StaticObject {
	Cheerio * Cheerios[CHEERIOS_NUMBER];
public:
	inline Road() {
		int currentCheerio = 0;
		//Cheerio * c = new Cheerio(0, -8, 0);
		//Cheerios[0] = c;
		//32 cheerios
		for (int i = -8; i < 8; i++) { //exterior horizontal
			Cheerios[currentCheerio++] = new Cheerio(i, 8, 0); 
			Cheerios[currentCheerio++] = new Cheerio(i, -8, 0); 
		}
		//20
		for (int i = -5; i < 5; i++) { // interior horizontal
			Cheerios[currentCheerio++] = new Cheerio(i, 5, 0);
			Cheerios[currentCheerio++] = new Cheerio(i, -5, 0);
		}
		//30
		for (int i = -7; i < 8; i++) { //exterior vertical
			Cheerios[currentCheerio++] = new Cheerio(-9, i, 0);
			Cheerios[currentCheerio++] = new Cheerio(8, i, 0);
		}
		//18
		
		for (int i = -4; i < 5; i++) { //interior vertical
			Cheerios[currentCheerio++] = new Cheerio(-6, i, 0);
			Cheerios[currentCheerio++] = new Cheerio(5, i, 0);
		}

	}
	inline ~Road() {}
	inline void draw() {
		glColor3d(0.5, 0.35, 0.05);
		for (int i = 0; i < CHEERIOS_NUMBER; i++) {
			Cheerios[i]->draw();
		}
	}
	Cheerio *getCheerios() { return Cheerios[100]; }
	
};