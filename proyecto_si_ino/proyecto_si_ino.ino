
#include <Ethernet.h>

#include <SPI.h>

// Configuracion del Ethernet Shield

//byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//IPAddress server(192, 168, 1, 4); 

byte mac[] = {
  0x70, 0x62, 0xB8, 0x75, 0x0B, 0x16
};

IPAddress ip(192,168,1,150); // Direccion IP del Arduino
IPAddress server(192,168,1,4); // Direccion IP del servidor

//IPAddress ip(192, 168, 1, 177);

//IPAddress gateway(190, 96, 240, 1);

//IPAddress subnet(255, 255, 255, 0);
//IPAddress dnserver(201, 221, 151, 31);

//EthernetServer server(80);
EthernetClient client;

int BOTON1 = 6;
int BOTON2 = 7;
int p1;
int p2;
int boton;


void setup() {
  pinMode(BOTON1, INPUT);
  pinMode(BOTON2, INPUT);
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  delay(6000); // Esperamos 1 segundo de cortesia
}

void loop(void) {
  p1 = digitalRead(BOTON1);
  p2 = digitalRead(BOTON2);

//  maquina = "a_uno";
  // Proceso de envio de muestras al servidor
  Serial.println("Connecting...");
   //Serial.println(client.connect(server, 80));
  if (client.connect(server, 80)>0) { // Conexion con el servidor
    if (p1 == HIGH) {
      boton = 1;
    } else if (p2 == HIGH) {
      boton = 2;
    }
    Serial.println(boton);
    Serial.print("GET proyecto_si_ino/iot.php?maquina=a_uno&boton=");
    Serial.println(boton);
 
    
    client.print("GET proyecto_si_ino/iot.php?maquina=a_uno&boton="); // Enviamos los datos por GET
    client.print(boton);
  
  
  //  client.print(maquina);

   // client.print("&boton="); // Enviamos los datos por GET
   

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
  //delay(60000);
}

