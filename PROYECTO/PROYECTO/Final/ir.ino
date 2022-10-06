








void infrarrojo()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
 // if (digitalRead(aumentar) == HIGH && digitalRead(disminuir) == HIGH)
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
    angulo=0;
        servomotor.write(angulo);
         digitalWrite(ledverde, HIGH);
 digitalWrite(ledrojo, LOW);
 digitalWrite(buzzer, LOW);
otro=1;
        // Esperamos 1 segundo
        delay(200);
    break;

  case 0xFF629D:  
    Serial.println(" CH             "); 
        // Desplazamos a la posición 90º
        angulo=45;
      servomotor.write(angulo);
     otro=1;
      // Esperamos 1 segundo
      delay(200);
    break;

  case 0xFFE21D:  
    Serial.println(" CH+            "); 
      // Desplazamos a la posición 180º
      angulo=90;
  servomotor.write(angulo);
  digitalWrite(ledverde, LOW);
 digitalWrite(ledrojo, HIGH);
 digitalWrite(buzzer, HIGH);
  otro=1;
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



  delay(300);


} //END translateIR



/* ( THE END ) */
