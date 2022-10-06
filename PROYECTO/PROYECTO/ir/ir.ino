#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <Servo.h>

Servo servoMotor;


/*-----( Declare Constants )-----*/
int ledverde= 3;
int ledrojo= 5;
int buzzer= 6;
int receiver = 2; // pin 1 of IR receiver to Arduino digital pin 11
int led1 = 8;
int rebote_led1;
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
/*-----( Declare Variables )-----*/


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1, OUTPUT);
  rebote_led1=0;
  servoMotor.attach(9);
  pinMode(ledverde, OUTPUT) ;
 pinMode(ledrojo, OUTPUT) ;
 pinMode(buzzer, OUTPUT) ;
servoMotor.write(0);
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
//    Serial.println(results.value, HEX);  UN Comment to see raw values
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
  
  
}/* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/
void translateIR() // takes action based on IR code received

// describing Car MP3 IR codes 

{
Serial.println(results.value);
  switch(results.value)

  {

  case 0xFFA25D:  
    Serial.println(" CH-            "); 
    // Desplazamos a la posición 0º
        servoMotor.write(0);
         digitalWrite(ledverde, HIGH);
 digitalWrite(ledrojo, LOW);
 digitalWrite(buzzer, LOW);
        // Esperamos 1 segundo
        delay(200);
    break;

  case 0xFF629D:  
    Serial.println(" CH             "); 
        // Desplazamos a la posición 90º
      servoMotor.write(45);
      // Esperamos 1 segundo
      delay(200);
    break;

  case 0xFFE21D:  
    Serial.println(" CH+            "); 
      // Desplazamos a la posición 180º
  servoMotor.write(90);
  digitalWrite(ledverde, LOW);
 digitalWrite(ledrojo, HIGH);
 digitalWrite(buzzer, HIGH);
  // Esperamos 1 segundo
  delay(200);
    break;

  case 0xFF22DD:  
    Serial.println(" PREV           "); 
    break;

  case 0xFF02FD:  
    Serial.println(" NEXT           "); 
    break;

  case 0xFFC23D:  
    Serial.println(" PLAY/PAUSE     "); 
    break;

  case 0xFFE01F:  
    Serial.println(" VOL-           "); 
    break;

  case 0xFFA857:  
    Serial.println(" VOL+           "); 
    break;

  case 0xFF906F:  
    Serial.println(" EQ             "); 
    break;

  case 0xFF6897:  
    Serial.println(" 0              "); 

    digitalWrite(led1, 0);
    break;

  case 0xFF9867:  
    Serial.println(" 100+           "); 
    break;

  case 0xFFB04F:  
    Serial.println(" 200+           "); 
    break;

  case 0xFF30CF:  
    Serial.println(" 1              "); 
    digitalWrite(led1, 1);
    break;

  case 0xFF18E7:  
    Serial.println(" 2              "); 
    break;

  case 0xFF10EF:  
    Serial.println(" 4              "); 
  break;


  case 0xFF7A85:  

    break;

  case 0xFF38C7:  
    Serial.println(" 5              "); 

    break;

  case 0xFF5AA5:  
    Serial.println(" 6              "); 
    digitalWrite(led1, 1);
    rebote_led1 = 1;
    break;

  case 0xFF42BD:  
    Serial.println(" 7              "); 
   digitalWrite(led1, 0);
   rebote_led1 = 0;
    break;

  case 0xFF4AB5:  
    Serial.println(" 8              "); 
    
    break;

  case 0xFF52AD:  
    Serial.println(" 9              "); 
    rebote_led1 = 1- rebote_led1;
    digitalWrite(led1, rebote_led1);
    break;

  default: 
    Serial.println(" other button   ");

  }
if(analogRead(9)==0){
  
  }
  if(analogRead(9)==90){
    
  }
  
  delay(300);


} //END translateIR



/* ( THE END ) */
