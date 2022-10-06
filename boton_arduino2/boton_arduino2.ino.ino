#include <Time.h>




const int LED=6;
const int BOTON=7;
int val;
void setup(){
pinMode(LED,OUTPUT);
pinMode(BOTON,INPUT);
Serial.begin(9600);   //start te serial monitor
setTime(16,56,50,18,05,2017);
}
void loop(){
   time_t t = now();//Declaramos la variable time_t t
   
val=digitalRead(BOTON);
if  (val==HIGH){
digitalWrite(LED,HIGH);
//Serial.println( "On");

//Imprimimos la fecha y la hora
  Serial.print(day(t));
  Serial.print(+ "/") ;
  Serial.print(month(t));
  Serial.print(+ "/") ;
  Serial.print(year(t)); 
  Serial.print( " ") ;
  Serial.print(hour(t));  
  Serial.print(+ ":") ;
  Serial.print(minute(t));
  Serial.print(":") ;
  Serial.println(second(t));
  delay(3000);//Esperamos 3 segundos


}
else { digitalWrite(LED,LOW);
Serial.println( "Off");
}
}


