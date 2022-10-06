/*
---------------------------------------------
Control ON/OFF de un motor
---------------------------------------------
Programa que hace uso de un motor y un pulsador,
mientras se mantenga pulsado, el motor debe
estar encendido (ON) de lo contrario debe estar
apagado (OFF)
Cosas de Mecatrónica y Tienda de Robótica
*/
//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int pulsador =7; 
int motor=3;
int led=13;
int buzzer = 9; 
int tono = 0;
//Declara Pin del potenciómetro
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
 //El pulsador como una entrada
pinMode(motor,OUTPUT);
pinMode(led,OUTPUT);
//El motor como una salida
}
//------------------------------------
//Funcion ciclicla

//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{
// cuando este energizado el Arduino
// Si el pulsador se encuentra oprimido
if(digitalRead(pulsador) == HIGH){
digitalWrite(motor,LOW); //Enciende el motor
digitalWrite(led,LOW);
}
else{ //si el pulsador no esta oprimido
digitalWrite(motor,HIGH); //Apaga el motor
digitalWrite(led,HIGH);
}
}
// Fin programa
