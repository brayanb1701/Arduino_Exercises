/* Realizado: Ing. Nelson Peña.
   Software: Programación de un Led Rgb.
*/
int led_rojo  = 8; 
int led_verde = 9; 
int led_azul  = 10;  
int espera    = 2000;

void setup() {
/*----- Se inicializan pines PWM como salida*/  
  pinMode(led_rojo, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
}
 
void loop() {
  analogWrite(led_rojo,255); // Se enciende color rojo
  delay(espera);
  analogWrite(led_rojo,0);   // Se apaga color rojo

  analogWrite(led_verde,255); // Se enciende color verde
  delay(espera);
  analogWrite(led_verde,0);   // Se apaga color verde

  
  analogWrite(led_azul,255); // Se enciende color azul
  delay(espera);
  analogWrite(led_azul,0);   // Se apaga color azul
  
  analogWrite(led_rojo,0);analogWrite(led_verde,0);analogWrite(led_azul,0); //Apaga todos los colores
// color amarillo
  analogWrite(led_rojo,255); 
  analogWrite(led_verde,255); 
  analogWrite(led_azul,0);
  delay(espera);
  
  analogWrite(led_rojo,0);analogWrite(led_verde,0);analogWrite(led_azul,0); //Apaga todos los colores
// color Naranja
  analogWrite(led_rojo,255); 
  analogWrite(led_verde,190); 
  analogWrite(led_azul,0);
  delay(espera);
  
  analogWrite(led_rojo,0);analogWrite(led_verde,0);analogWrite(led_azul,0); //Apaga todos los colores
  // color Rosado
  analogWrite(led_rojo,255); 
  analogWrite(led_verde,0); 
  analogWrite(led_azul,255);
  delay(espera);
  
  analogWrite(led_rojo,0);analogWrite(led_verde,0);analogWrite(led_azul,0); //Apaga todos los colores
// color Blanco
  analogWrite(led_rojo,255); 
  analogWrite(led_verde,255); 
  analogWrite(led_azul,255);
  delay(espera);
  
  analogWrite(led_rojo,0);analogWrite(led_verde,0);analogWrite(led_azul,0); //Apaga todos los colores
}
