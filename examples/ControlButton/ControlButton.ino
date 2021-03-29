/*
  Autor	  : Roberto Mota
  Projeto	: Biblioteca para utilização de pushbuttons PULLUP
  Data	  : 2020/11/27
  Obs		  :
            O pino referente ao botão é automaticamente programado como saida!
            ControlButton *SUA VARIAVEL* (Pino Botão, tempo de debounce, (Modo PULLUP ou PULLDOWN));

            DEBOUNCE = Devido a mecânica dos pushbuttons, existe uma interferencia durante o pressionar ou despressionar
                        O debounce consome tempo de memoria para ignorar essas interefencias.
                        Caso use filtro capacitivo, considere o valor de DEBOUNCE = 0;
                
            activeDown(); Acionamento por borda de descida.
            activeUp();   Acionamento por borda de subida.
*/
#include <ControlButton.h>

ControlButton botao(2, 100, true);    //(pino do botão, tempo de debounce, (true = pullup, false = pulldown));
								


void setup() {
  pinMode(13, OUTPUT);

}

void loop() {
  //Ao despressionar o botão, o LED nativo na porta 13 (uno, nano, etc) irá trocar de estado!
  if (botao.activeDown() == 1)
  {
    digitalWrite(13, !digitalRead(13));
  }

}
