// ESTE ES UN ARCHIVO FUENTE

#include "lib/include.h"
// ESTE PROGRAMA ES DECLARADO EN SU LIBRERÍA COMO PROTOTIPO DE FUNCIÓN

extern void Configurar_GPIO(void)
{
    SYSCTL->RCGCGPIO |=(1<<4); // 1) Activación del reloj
    GPIOE->LOCK= 0x4C4F434B;   // 2) unlock GPIO Port F
    GPIOE->CR = 0xF0; 
    // Ej. GPIOF->CR = 0x1F; // Permite cambios del puerto PF4 al 0.
    GPIOE->AMSEL = 0x00;        // 3) disable analog on PE
    GPIOE->PCTL = 0x00000000;   // 4) PCTL GPIO on PF4-0
    GPIOE->DIR = 0x10; // 5) PE4 in, PF5 out
    GPIOE->AFSEL = 0x30; // 6) Habilitación de funciones alternativas en PE4, PE5
    GPIOE->PUR = 0x30;          // enable pull-up on PE4 and PE5
    GPIOE->DEN = (1<<4) | (1<<5);          // 7) enable digital I/O on PE4 y PE5
}

extern void Delay(void)
{
  unsigned long volatile time;
  time = 1600000;
  while(time)
  {
		time--;
  }
} 