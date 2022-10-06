

 
void joystick()
{
 delay(100);                    
 int joystickXVal = analogRead(XJOY_PIN) ;  //read joystick input on pin A1
 int servo= map(joystickXVal, 0, 1022, 0, 90);
 if(otro==0 && (joystickXVal<=450 || joystickXVal>=510)){
 Serial.print(joystickXVal);                //print the value from A1
 Serial.println(" = input from joystick");  //print "=input from joystick" next to the value
 Serial.print(servo);       //print a from A1 calculated, scaled value
 Serial.println(" = output to servo");      //print "=output to servo" next to the value
 Serial.println() ;
 servomotor.write(servo);      //write the calculated value to the servo  
 digitalWrite(ledverde, HIGH);
 digitalWrite(ledrojo, LOW);
 digitalWrite(buzzer, LOW);
 otro=1;
 }
while(servo>70 && joystickXVal>=400){
 servo= map(joystickXVal, 480, 505, 90, 90);
 servomotor.write(servo); 
 delay(100);
 digitalWrite(ledverde, LOW);
 digitalWrite(ledrojo, HIGH);
 digitalWrite(buzzer, HIGH);
 joystickXVal = analogRead(XJOY_PIN) ;
 
 }

 
}
