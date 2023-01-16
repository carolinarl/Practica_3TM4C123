#include "lib/include.h"

int main(void)
{
    uint16_t valor = 0;
    char c='5';
    //char b='a';
    Configurar_PLL(_40MHZ);  //Configuracion del reloj
    Configurar_UART5();  //Configuración del UART
    //-fclk 40MHZ Baud-rate 28800
    Configurar_GPIO();

    //Experimento 1
    //  Configurar_UART1(); //Jorge,Alberto,Navarro,Saul,Fabela -fclk 25MHZ Baud-rate 57600
    //  Configurar_UART7(); //Angel,Fernanda,Sonia,Aleidis,Monse -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART4(); //Argelia,Roxana,Yesica,Vanesa,Christian,Abiu -fclk 10MHZ Baud-rate 4800
    //  Configurar_UART2(); //Brizet,Monse,Luis,Majo,Alonso -fclk 40MHZ Baud-rate 115200
    //  Configurar_UART3(); //Jesus,Yesica,Carlos,Dulce,Rodolfo,Leonardo -fclk 80MHZ Baud-rate 19200
    //  Configurar_UART2(); //Andrea,Avila,Pamela,Paulina -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART5(); //Hector,Cecilia,Carolina,Jozzafat -fclk 40MHZ Baud-rate 28800


    while (1)
    {
        int i = 0;
        char string[20] = "NULL";          //Creación de un vector o cadena vacía
        i = readString('%', string);       //Lectura de caracteres, guardado en "string"
        INVERSION(string, i);              //Inversión de la cadena formada
        char string_num[i*2];              //Creación de espacios entre la cadena
        NUMEROS(string, string_num, i);    
        //Envío de la versión actual de la cadena y la cadena vacía del doble de longitud que la original
        printString(string_num);           //Escritura de la cadena final "string_num"
    }
    
    
}