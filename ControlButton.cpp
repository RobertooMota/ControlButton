#include "ControlButton.h"
ControlButton::ControlButton(int pin, int tempodebounce, bool pullUp)
{
  if (pullUp == true)
  {
    pinMode(pin, INPUT_PULLUP);
    debounce = tempodebounce;
    pino = pin;
    modoPULLUP = true;
	
	 //Serial.begin(9600);
    //Serial.print("PULLUP");
    //Serial.end();
	
  } else {
    pinMode(pin, INPUT);
    debounce = tempodebounce;
    pino = pin;
    modoPULLUP = false;
	
    //Serial.begin(9600);
    //Serial.print("PULLDOWN");
    //Serial.end();
  }
}




ControlButton::activeDown()
{

  atual = digitalRead(pino);
  
  if (atual == !0 && anterior == !1)
  {
    pressionado = 1;
    delay(debounce);
  }
  anterior = atual;

  if (pressionado == 1)
  {
    pressionado = 0;
    return 1;
  } else {
    return 0;
  }
}

ControlButton::activeUp()

{
  atual = digitalRead(pino);

  if (atual == !1 && anteriorD == !0)
  {
    pressionado = 1;
    delay(debounce);
  }
  anteriorD = atual;

  if (pressionado == 1)
  {
    pressionado = 0;
    return 1;
  } else {
    return 0;
  }

}

ControlButton::noDebounce()
{
	return digitalRead(pino);	
}