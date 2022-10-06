



void botones() {
//servomotor.write(angulo);
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
     if (angulo > 90)
    {
      angulo = 90;
    }
    servomotor.write(angulo);
    delay(5);
    otro=1;
    Serial.print("aumentar"); 
Serial.print(digitalRead(aumentar)); 
Serial.println(angulo); 
   
  }

  //Disminuye el angulo mientras se mantenga presionado
  //El angulo no disminuye mas alla de 0 grados
  if (digitalRead(disminuir) == LOW)
  {
    angulo--;
    if (angulo < 0)
    {
      angulo = 0;
    }
    servomotor.write(angulo);
    delay(5);
    otro=1;
     Serial.print("disminuir"); 
    Serial.print(digitalRead(disminuir)); 
Serial.println(angulo); 

    
  }
}
