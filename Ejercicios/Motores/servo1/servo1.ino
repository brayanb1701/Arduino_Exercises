/* Realizado: Ing. Nelson Peña.
   Software: Programación de un ServoMotor.
*/
#include <Servo.h>

Servo miServo;//crea un Objeto para manejar un ServoMotor.
int espera = 100;
void setup()
{
  miServo.attach(13);//Asociamos el servomotor al pin 13 del Arduino 
  miServo.write(0);// 0 grados al ServoMotor
  delay(espera);
}
/*************************************************/
void loop()
{  
    miServo.write(0);
    delay (espera);
    miServo.write(30);
    delay (espera);
    miServo.write(60);
    delay (espera);
    miServo.write(90);
    delay (espera);
    miServo.write(120);
    delay (espera);
    miServo.write(150);
    delay (espera);
    miServo.write(180);
    delay (espera);
  
}
/**************************************************/

