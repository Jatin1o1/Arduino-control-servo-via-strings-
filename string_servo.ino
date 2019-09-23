#include<Servo.h>

Servo myservo;
const int m1=52;   // motor pin no 1
const int m2=53; // motor pin no 2

void setup() {
  myservo.attach(9);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  Serial.begin(9600);
  myservo.write(0);
  digitalWrite(m1,LOW); 
  digitalWrite(m2,LOW);
}

void loop() {
  while (Serial.available()) {
    String s= Serial.readString();
    s.trim();
    //Serial.println(s);
    if (s == "md") {/*Serial.println("down");*/myservo.write(0); digitalWrite(m1,HIGH); digitalWrite(m2,LOW);}
    if (s == "mu") {/*Serial.println("up");*/myservo.write(30);digitalWrite(m2,HIGH); digitalWrite(m1,LOW);}
    if (s == "ml") {/*Serial.println("left");*/myservo.write(60);digitalWrite(m1,HIGH); digitalWrite(m2,LOW);}
    if (s == "mr") {/*Serial.println("right");*/myservo.write(90);digitalWrite(m1,HIGH); digitalWrite(m2,LOW);}
    

  }
}
