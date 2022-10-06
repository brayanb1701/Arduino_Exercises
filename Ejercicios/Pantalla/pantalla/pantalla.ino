#include <SPI.h>
 
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() 
   {
       lcd.begin(21, 2);       // Fijamos el numero de caracteres y filas
       lcd.autoscroll();
       lcd.print(" Metrolinea nos mueve");  // Aqi va el mensaje
        for (int thisChar = 0; thisChar < 20; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
       
   }

void loop()
   {
       lcd.setCursor(6, 1);    // Posicion, Num. linea
       String s = reloj() ;
       lcd.print(s) ;
   }
  
String reloj()
   {
       int n = millis() / 1000 ;       // Lo pasamos a segundos
       int segundos = n % 60  ;
       int minutos =  n / 60  ;

       String S = String(minutos) + ":" + String(segundos);
       return (S);
   }
