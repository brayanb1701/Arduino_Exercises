
const int sensorPin= A0;

void setup(){

Serial.begin(9600);   //start te serial monitor
//setTime(16,56,50,25,05,2017);
}
void loop(){

int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  Serial.print(celsius);
  Serial.println(" C");
  delay(1000);
}


