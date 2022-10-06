/* Realizado: Ing. Nelson Peña.
   Software: Programación de un JoyStick, dependiendo de la orientación enciende un determinado Led.
*/
int X     = 0;
int Y     = 0;
int led1  = 8;
int led2  = 9;
int led3  = 10;
int led4  = 11;
int led5  = 12;
void setup() 
{  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}
void loop() {
X = analogRead(0); // Lee el puerto analogo A0
Y = analogRead(1); // Lee el puerto analogo A1
// El punto medio es X= 507 o 508 y Y= 513
// Extremo uno X = 0 y Y = 0
// Extremo dos X = 1023 y Y = 1023
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
if ( ( (X == 507) || (X == 508) ) && (Y == 513) ) {
  Serial.println("Esta Stop"); 
  digitalWrite(led5, HIGH);
}else{
  if (X == 0) {
    Serial.println("Izquierda"); 
    digitalWrite(led1, HIGH);
    digitalWrite(led5, LOW);
  }
  if (X == 1023) {
    Serial.println("Derecha"); 
    digitalWrite(led2, HIGH);
    digitalWrite(led5, LOW);
  }
  
  if (Y == 0) {
    Serial.println("Arriba"); 
    digitalWrite(led3, HIGH);
    digitalWrite(led5, LOW);
  }
  if (Y == 1023) {
    Serial.println("Abajo"); 
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
  }
}


delay(100);
}


