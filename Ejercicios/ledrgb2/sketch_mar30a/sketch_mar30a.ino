int pinRojo = 8;
int pinAmarillo = 10;
int pinVerde = 12;
void setup() {
  // put your setup code here, to run once:
pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
setColor(0, 255, 255); // rojo
  delay(500);
   setColor(0, 0 , 255); // amarillo
  delay(500); 
  setColor(255, 0, 255); // verde
  delay(500);
}
void setColor(int red, int yellow, int green){
  analogWrite(pinRojo, red);
  analogWrite(pinAmarillo, yellow);
  analogWrite(pinVerde, green); 
}
