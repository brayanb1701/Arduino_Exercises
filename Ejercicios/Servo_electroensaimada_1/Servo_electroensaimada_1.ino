#include <Servo.h>

/*Tutorial Servomotor Arduino
www.electroensaimada.com
Autor:Toni Ruiz Sastre
*/

Servo miServo;

void setup(){
 miServo.attach(9);

}


void loop(){

 miServo.write(90);  


}
