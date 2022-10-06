#include <Servo.h>
#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
Servo myservo ;
int ledverde= 12;
int ledrojo= 13;
int buzzer= 11;
void setup()
{
 Serial.begin(9600);
 pinMode(VOUT_JOY_PIN, OUTPUT) ;    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN, OUTPUT) ;  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN,LOW) ; //set pin A3 to low (ground)
 myservo.attach(9,600,1500);
 pinMode(ledverde, OUTPUT) ;
 pinMode(ledrojo, OUTPUT) ;
 pinMode(buzzer, OUTPUT) ;

}
 
void loop()
{
 delay(100);                    
 int joystickXVal = analogRead(XJOY_PIN) ;  //read joystick input on pin A1
  int servo= map(joystickXVal, 480, 1022, 0, 90);
 Serial.print(joystickXVal);                //print the value from A1
 Serial.println(" = input from joystick");  //print "=input from joystick" next to the value
 Serial.print(servo);       //print a from A1 calculated, scaled value
 Serial.println(" = output to servo");      //print "=output to servo" next to the value
 Serial.println() ;
 myservo.write(servo);      //write the calculated value to the servo  
 digitalWrite(ledverde, HIGH);
 digitalWrite(ledrojo, LOW);
 digitalWrite(buzzer, LOW);
while(servo>70 && joystickXVal>=400){
 servo= map(joystickXVal, 480, 505, 90, 90);
 myservo.write(servo); 
 delay(100);
 digitalWrite(ledverde, LOW);
 digitalWrite(ledrojo, HIGH);
 digitalWrite(buzzer, HIGH);
 joystickXVal = analogRead(XJOY_PIN) ;
 
 }

 
}
