/* Realizado: Ing. Nelson Peña.
   Software: Parpadeo de LED.
   Video: Codigo Facilito N0. 02.
*/
// Parpadeo de LED
void setup() {
  // put your setup code here, to run once:
pinMode(10, OUTPUT); //declaramos el pin 13 como salida
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10, HIGH);// encendemos el LED
delay(1000); // esperamos 1 segundo
digitalWrite(10, LOW); // apagamos el LED
delay(1000); // esperamos 1 segundo

}
