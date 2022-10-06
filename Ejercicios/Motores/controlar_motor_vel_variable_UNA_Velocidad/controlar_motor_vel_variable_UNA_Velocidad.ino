/* Realizado: Ing. Nelson Peña.
   Software: Programación de un Motor con control de velocidad
*/
int motor=3;     //Declara Pin del motor
 
void setup() {
  Serial.begin(9600); 
}
 
 
void loop() {
 
  // Si hay algun valor en la Consola Serial

      analogWrite(motor,'1');

}
