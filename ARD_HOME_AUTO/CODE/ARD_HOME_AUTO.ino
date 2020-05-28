#include <Servo.h>
#define trigPin 10
#define echoPin 13
Servo myservo;      

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(7,OUTPUT); 
  pinMode(8, INPUT);
  myservo.attach(9); 
}

void loop() 
{
  float duration, distance;
  
      if(digitalRead(8)== HIGH)
        {
          digitalWrite(7, HIGH);   
          delay(1000);                    
          digitalWrite(7,LOW);                       
          digitalWrite(8,LOW);
        }
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  Serial.print(distance);
      if (distance >= 2 && distance <= 8)
        {
          myservo.write(0); 
          digitalWrite(7,HIGH);
          delay(1000);
        }
      else
        {
          myservo.write(110); 
          digitalWrite(7,LOW);
          delay(3);
        }
 
}
