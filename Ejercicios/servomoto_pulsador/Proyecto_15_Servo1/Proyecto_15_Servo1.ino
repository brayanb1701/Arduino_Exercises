#include <Servo.h>
Servo servomotor;

void setup() {
  servomotor.attach(6); //Pin PWM 6 del Arduino
}

void loop() {

  //Aumenta el angulo en +1 hasta llegar a 180 grados
  for (int posicion = 0; posicion <= 180; posicion++)
  {
    servomotor.write(posicion);
    delay(10);
  }

  //Disminuye el angulo en -1 hasta llegar a 0 grados
  for (int posicion = 180; posicion >= 0; posicion--)
  {
    servomotor.write(posicion);
    delay(10);
  }
}
