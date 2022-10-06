/*
 ---------------------------------------------
 Generar sonido con un Buzzer
 ---------------------------------------------
*/
 
//--------------------------------------------------
//Declarar puertos de entradas y salidas y variables
//--------------------------------------------------
int buzzer = 9;  //Pin del buzzer
int tono = 0;    //Pin del potenciometro
 
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  // No se configuran parametros inciales, pero se
  //coloca la función setup()
}
 
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{           //  cuando se da energia al Arduino
 
  //Variable donde se almacena el valor del potenciometro
  int sensor = analogRead(tono);
 
  //Variable donde se escala la frecuencia de 100 a 5000Hz
  int frecuencia = map(sensor,0,1023,100,5000);
 
  //Variable para guardar el tiempo
  int duracion = 250;
 
  //Funcion tone() que recibe:
  //  1ra posición: Pin del elemento sonoro
  //  2da posición: Frecuencia en Hz
  //  3ra posición: Duración del tono
  tone(buzzer, frecuencia, duracion);
 
  delay(100);

    }
