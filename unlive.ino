
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(9, 10); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

int motorPin1 = 5; //vibrator
int motorPin2 = 6;

int i;

void setup()
{

  pinMode(2, OUTPUT); //LED 1 roja
  pinMode(3, OUTPUT); //LED 2 blanca

  pinMode(4, OUTPUT); // HOT

  pinMode(5, OUTPUT); // vibrator motor1
  pinMode(6, OUTPUT); // vibrator motor2
  
  Serial.begin(9600);

  //musica

  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  Serial.println();
  Serial.println(F("DFPlayer Mini Demo"));
  Serial.println(F("Initializando modulo MP3 ... (Puede llevar 3~5 segundos)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) { //
    Serial.println(F("No se puede iniciar:"));
    Serial.println(F("1.Please revisa las conexiones!"));
    Serial.println(F("2.Inserta la tarjeta SD!"));
    while (true);

  }

  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communicacion time out 500ms

  myDFPlayer.volume(20); // Set volumen (0~30).

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  //

  // myMP3.reset();
  // myDFPlayer.play(2);
}


void loop() {

  if (analogRead(A0) < 500) {
    //HOT
    digitalWrite(4, 255);

    delay(5000);
    //musica
    myDFPlayer.play(1);

    //LEDS rojo
    digitalWrite(2, HIGH);    // turn LED 1 on
    delay(2000);
    digitalWrite(2, LOW);

    //vibrator

    digitalWrite(6, 100);//30% on off
    delay(2000);
    digitalWrite(6, 50);

    //led blanco
    digitalWrite(3, HIGH);    // turn LED 1 on
    delay(2000);
    digitalWrite(3, LOW);

  //VIBRADOR
    digitalWrite(5, 100);//30% on off
    digitalWrite(6, 100);
    delay(2000);

    //led blanco
    digitalWrite(3, HIGH);    // turn LED 1 on
    delay(3000);
    digitalWrite(3, LOW);
    delay(2000);
    digitalWrite(3, HIGH);

    //LEDS rojo
    digitalWrite(2, HIGH);    // turn LED 1 on
    delay(2000);
    digitalWrite(2, LOW);

    //apagar vibradores
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    delay(4000);

    //vibradores on
    digitalWrite(5, 100);//30% on off
    digitalWrite(6, 100);
    delay(3000);
    
  //led blanco
    digitalWrite(3, LOW);
    delay(3000);
    digitalWrite(3, HIGH);    // turn LED 1 on
    delay(3000);
    digitalWrite(3, LOW);
    
    //LEDS rojo
    digitalWrite(2, HIGH);    // turn LED 1 on
    delay(2000);
    digitalWrite(2, LOW);
    
    //apagar HOT
    analogWrite(4, 0); //255 maxim

    //apagar vibradores
    digitalWrite(6, 0);
    digitalWrite(5, 0);

    //apagar sonido
   myDFPlayer.stop();

   //spagar calor
   analogWrite(4, 0);

  }
}
