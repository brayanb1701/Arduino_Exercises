#include <Servo.h>
Servo servomotor;

int angulo;
int aumentar = 22;  //Pin para el pulsador de aumentar el angulo
int disminuir = 23; //Pin para el pulsador de disminuir el angulo

void setup() {

  servomotor.attach(6);  //Pin PWM 6 del Arduino
  pinMode(disminuir, INPUT);
  pinMode(aumentar, INPUT);
}

void loop() {

  //Aumenta el angulo mientras se mantenga presionado
  //El angulo no aumenta mas alla de 180 grados
  if (digitalRead(aumentar) == LOW)
  {
    angulo++;
    servomotor.write(angulo);
    delay(10);

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
    delay(10);

    if (angulo < 0)
    {
      angulo = 0;
    }
  }
}
