/* Realizado: Ing. Nelson Peña.
   Software: Programación de un JoyStick, dependiendo de la orientación enciende un determinado Led en formato RGB.
*/
int X         = 0;
int Y         = 0;
int led_rojo  = 8; 
int led_verde = 9; 
int led_azul  = 10;  
int espera    = 100;
void setup() 
{  
  Serial.begin(9600);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
  analogWrite(led_rojo,0);   // Se apaga color rojo
  analogWrite(led_verde,0);   // Se apaga color verde
  analogWrite(led_azul,0);   // Se apaga color azul
}
void loop() {
X = analogRead(0); // Lee el puerto analogo A0
Y = analogRead(1); // Lee el puerto analogo A1
// El punto medio es X= 507 o 508 y Y= 513
// Extremo uno X = 0 y Y = 0
// Extremo dos X = 1023 y Y = 1023

 
if ( ( (X == 507) || (X == 508) ) && (Y == 513) ) {
  Serial.print("Esta Stop");   Serial.print("   X:");Serial.print(X);  Serial.print("   Y: ");Serial.println(Y); 
 
  analogWrite(led_rojo,0); 
  analogWrite(led_verde,0); 
  analogWrite(led_azul,0);
}else{
  if (X == 0) {
    Serial.print("Izquierda");   Serial.print("   X:");Serial.print(X);  Serial.print("   Y: ");Serial.println(Y); 
  analogWrite(led_rojo,0); 
  analogWrite(led_verde,0); 
  analogWrite(led_azul,255);
  }
  if (X == 1023) {
    Serial.print("Derecha");   Serial.print("   X:");Serial.print(X);  Serial.print("   Y: ");Serial.println(Y); 
  analogWrite(led_rojo,255); 
  analogWrite(led_verde,0); 
  analogWrite(led_azul,0);
  }
  
  if (Y == 0) {
    Serial.print("Arriba");   Serial.print("   X:");Serial.print(X);  Serial.print("   Y: ");Serial.println(Y); 
  analogWrite(led_verde,255); 
  analogWrite(led_azul,0);
  }
  if (Y == 1023) {
    Serial.print("Abajo");   Serial.print("   X:");Serial.print(X);  Serial.print("   Y: ");Serial.println(Y); 
  analogWrite(led_rojo,255); 
  analogWrite(led_verde,255); 
  analogWrite(led_azul,255);
  }
}


delay(espera);
}


