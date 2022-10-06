//Variables:
int velocidad; //Variable de la velocidad

void setup() {
  pinMode(2, INPUT); //Irá conectado un botón en la patilla 2
  pinMode(3, OUTPUT); //Irá conectado el motor a la patilla 3
}

void loop() {
  
  if(digitalRead(2)==HIGH){
    //For que hara que la variable velocidad incremente
    for(velocidad=0;velocidad < 256;velocidad++){
      analogWrite(3, velocidad); //Incremento en el voltaje en la patilla 3
      delay(25); //Retardo que define la rapidez en el aumento de la velocidad
    }
  }
  else{
    //Si el boton no esta presionado
    digitalWrite(3, LOW); //Apaga el motor
  }
  
  delay(100); //Retardo de lectura del boton
}
