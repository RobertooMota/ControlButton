#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H
#include <Arduino.h>

class ControlButton
{
		
	public:
		ControlButton(int pin, int tempodebounce = 200, bool pullUp = true);
		int activeDown();
		int activeUp();
		int noDebounce();
		
	private:
		int pino;
		int debounce;
		bool atual;
		bool anterior = 1;
		bool anteriorD = 0;
		bool pressionado = 0;
		bool modoPULLUP = false;
	
};
#endif