
int buzzer = 9; 
int tono = 0;

void setup() 
{

}

void loop() 
{

int sensor = analogRead(tono);

int frecuencia = map(sensor,0,1023,100,5000);

int duracion = 250;
//Funcion tone(), que recibe:
// 1ra posición: Pin del elemento sonoro
// 2da posición: Frecuencia deseada en Hz
// 3ra posición: Duración del tono
tone(buzzer, frecuencia, duracion);
}

delay(100);
//Fin programa
