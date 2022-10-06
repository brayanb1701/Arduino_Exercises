
#include <Servo.h>
Servo servomotor;

int angulo;
int aumentar = 2;  //Pin para el pulsador de aumentar el angulo
int disminuir = 1; //Pin para el pulsador de disminuir el angulo
int ledverde= 12;
int ledrojo= 13;
int buzzer= 11;
void setup() {

  servomotor.attach(9);  //Pin PWM 6 del Arduino
  pinMode(disminuir, INPUT);
  pinMode(aumentar, INPUT);
  pinMode(ledverde, OUTPUT) ;
 pinMode(ledrojo, OUTPUT) ;
 pinMode(buzzer, OUTPUT) ;

}

void loop() {
servomotor.write(angulo);
  //Aumenta el angulo mientras se mantenga presionado
  //El angulo no aumenta mas alla de 180 grados
  if(angulo==0){
    digitalWrite(ledverde, HIGH);
 digitalWrite(ledrojo, LOW);
 digitalWrite(buzzer, LOW);
  }
  if(angulo==90){
    digitalWrite(ledverde, LOW);
 digitalWrite(ledrojo, HIGH);
 digitalWrite(buzzer, HIGH);
  }
  if (digitalRead(aumentar) == LOW)
  {
    angulo++;
    servomotor.write(angulo);
    delay(5);

    if (angulo > 90)
    {
      angulo = 90;
    }
  }

  //Disminuye el angulo mientras se mantenga presionado
  //El angulo no disminuye mas alla de 0 grados
  if (digitalRead(disminuir) == LOW)
  {
    angulo--;
    servomotor.write(angulo);
    delay(5);

    if (angulo < 0)
    {
      angulo = 0;
    }
  }
}
