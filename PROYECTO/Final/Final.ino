#include <Servo.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
Servo servomotor;
#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
int angulo;
int aumentar = 2;  //Pin para el pulsador de aumentar el angulo
int disminuir = 1; //Pin para el pulsador de disminuir el angulo
int ledverde= 12;
int ledrojo= 13;
int buzzer= 11;
int receiver = 4; // pin 1 of IR receiver to Arduino digital pin 11
int led1 = 8;
int rebote_led1;
int otro=0;
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
/*-----( Declare Variables )-----*/



void setup() {
 Serial.begin(9600);
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1, OUTPUT);
  rebote_led1=0;
  servomotor.attach(9);  //Pin PWM 6 del Arduino
  pinMode(disminuir, INPUT);
  pinMode(aumentar, INPUT);
  pinMode(ledverde, OUTPUT) ;
 pinMode(ledrojo, OUTPUT) ;
 pinMode(buzzer, OUTPUT) ;
 pinMode(VOUT_JOY_PIN, OUTPUT) ;    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN, OUTPUT) ;  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN,LOW) ; //set pin A3 to low (ground)
}

void loop() {
  otro=0;
botones();
infrarrojo();
translateIR();
joystick();
}

