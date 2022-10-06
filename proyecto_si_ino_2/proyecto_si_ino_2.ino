#include <Ethernet.h>
#include <SPI.h>

// Configuracion del Ethernet Shield
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFF, 0xEE}; // Direccion MAC
byte ip[] = {192,168,10,200}; // Direccion IP del Arduino
byte server[] = {192,168,10,32}; // Direccion IP del servidor
EthernetClient client;

int BOTON1 = 6;
int BOTON2 = 7;
int p1;
int p2;
int boton;


void setup(void) {
  pinMode(BOTON1, INPUT);
  pinMode(BOTON2, INPUT);
  Serial.begin(9600);
  Ethernet.begin(mac, ip); // Inicializamos el Ethernet Shield
  delay(1000); // Esperamos 1 segundo de cortesia
}

void loop(void) {
  p1 = digitalRead(BOTON1);
  p2 = digitalRead(BOTON2);
  

  //if(p1==HIGH || p2==HIGH){

  // Proceso de envio de muestras al servidor
  Serial.println("Connecting...");
  if (client.connect(server, 80) > 0) { // Conexion con el servidor
    if (p1 == HIGH) {
      boton = 1;
    } else if (p2 == HIGH) {
      boton = 2;
    }
    Serial.println(boton);

   Serial.print("GET /proyecto_si_ino/iot.php?maquina=a_uno&boton="); // Enviamos los datos por GET
   Serial.print(boton);
   Serial.println(" HTTP/1.0");
   Serial.println();
    
    client.print("GET /proyecto_si_ino/iot.php?maquina=a_uno&boton="); // Enviamos los datos por GET
    client.print(boton);

   client.println(" HTTP/1.0");
   // client.println("User-Agent: Arduino 1.0");
   client.println();
    Serial.println("Conectado");
  } else {
    Serial.println("Fallo en la conexion");
  }
  if (!client.connected()) {
    Serial.println("Disconnected!");
  }
  client.stop();
  client.flush();

  boton=0;
  //delay(60000);

  //}
  
}
