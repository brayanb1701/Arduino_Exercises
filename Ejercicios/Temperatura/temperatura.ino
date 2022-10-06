/* Realizado: Ing. Nelson Peña.
   Software: Salidas Analogicas con una Perilla(Potenciometro ->> medir voltajes variables).
   Nota> En esta parte UTILIZA un LED Rgb. y un sensor de temperatura
   Video: Codigo Facilito N0. 07.
*/
const int sensor = 0;
const int ledRojo = 5;
const int ledAzul = 6;
long miliVolts;
long temperatura;
int brillo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
miliVolts = (analogRead(sensor) *  5000L) / 1023;
temperatura = miliVolts / 10;

brillo = map(temperatura, 10, 40, 0, 255);
brillo = constrain(brillo, 0, 255);

//analogWrite(ledRojo, brillo);
//analogWrite(ledAzul, 255 - brillo);

analogWrite(ledAzul, brillo);
analogWrite(ledRojo, 255 - brillo);


Serial.print("Temperatura: ");
Serial.print(temperatura);
Serial.println(" grados");
delay(200);
}
