//Servo
#include <Servo.h> //library servo
Servo myservo; //membuat variabel servo untuk dikendalikan 
int pos = 0; // deklarasi variabel untuk posisi sudut servo
//Ultrasonik
const int TRIGPIN = 3; // deklarasi output ultrasonik 
const int ECHOPIN = 2;// deklarasi input ultrasonik
long timer; // deklarasi waktu 
int jarak ; // deklarasi jarak servo

void setup() 
{
  //ultrasonik
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode (TRIGPIN, OUTPUT);
  //servo
  myservo.attach (9);
  }

void loop() {
  //ultrasonik
  digitalWrite(TRIGPIN, LOW); //matikan sesnsor ultrasonik
  digitalWrite (TRIGPIN, HIGH); //aktifkan sensor ultrasonik
  digitalWrite(TRIGPIN, LOW);
  timer = pulseIn (ECHOPIN, HIGH); //baca rentan waktu dari TRIGPIN HIGH sampai ECHOPIN HIGH
  jarak =  timer/58 ;// jarak ultrasonik

  Serial.print ("Jarak = ");
  Serial.print (jarak);
  Serial.print (" cm");
  Serial.println ();
 
  //servo ketika tempat sampah terbuka
  if (jarak >= 50) { 
    digitalWrite (3, HIGH);
    myservo.write (10);
    delay (1000);
  }
  // servo ketika tempat sampah tertutup
  else {
    digitalWrite (3,LOW);
    myservo.write (180);
    delay (1000);
  }
}

