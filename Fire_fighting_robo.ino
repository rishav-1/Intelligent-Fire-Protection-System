#include <Servo.h>  //include servo.h library
Servo myservo;
int pos = 0;     
boolean fire = false;
#define left 9      // left sensor 
#define right 10    // right sensor
#define forward 8   //front sensor
#define lM1 2       // left motor
#define lM2 3       // left motor
#define rM1 4       // right motor
#define rM2 5       // right motor
#define pump 6
 
void setup()
 
{
 
  pinMode(left, INPUT);
 
  pinMode(right, INPUT);
 
  pinMode(forward, INPUT);
 
  pinMode(lM1, OUTPUT);
 
  pinMode(lM2, OUTPUT);
 
  pinMode(rM1, OUTPUT);
 
  pinMode(rM2, OUTPUT);
 
  pinMode(pump, OUTPUT);
 
  myservo.attach(11);
 
  myservo.write(90); 
 
}
 
void put_off_fire()
 
{
 
    delay (500);
 
 
 
    digitalWrite(lM1, HIGH);
 
    digitalWrite(lM2, HIGH);
 
    digitalWrite(rM1, HIGH);
 
    digitalWrite(rM2, HIGH);
 
    
 
   digitalWrite(pump, HIGH);
 
   delay(500);
 
    
 
    for (pos = 50; pos <= 130; pos += 1) { 
 
    myservo.write(pos); 
 
    delay(10);  
 
  }
 
  for (pos = 130; pos >= 50; pos -= 1) { 
 
    myservo.write(pos); 
 
    delay(10);
 
  }
 
  
 
  digitalWrite(pump,LOW);
 
  myservo.write(90);
 
  
 
  fire=false;
 
}
 
 
 
void loop()
 
{
 
   myservo.write(90); 
 
 
 
    if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1) 
 
    {
 
    
 
    digitalWrite(lM1, HIGH);
 
    digitalWrite(lM2, HIGH);
 
    digitalWrite(rM1, HIGH);
 
    digitalWrite(rM2, HIGH);
 
    }
 
    
 
    else if (digitalRead(Forward) ==0) 
 
    {
 
    digitalWrite(lM1, HIGH);
 
    digitalWrite(lM2, LOW);
 
    digitalWrite(rM1, HIGH);
 
    digitalWrite(rM2, LOW);
 
    fire = true;
 
    }
 
    
 
    else if (digitalRead(Left) ==0)
 
    {
 
    digitalWrite(lM1, HIGH);
 
    digitalWrite(lM2, LOW);
 
    digitalWrite(rM1, HIGH);
 
    digitalWrite(rM2, HIGH);
 
    }
 
    
 
    else if (digitalRead(Right) ==0) 
 
    {
 
    digitalWrite(lM1, HIGH);
 
    digitalWrite(lM2, HIGH);
 
    digitalWrite(rM1, HIGH);
 
    digitalWrite(rM2, LOW);
 
    }
 
    
 
delay(300);//change this value to increase the distance
 
 
 
     while (fire == true)
 
     {
 
      put_off_fire();
 
     }
 
}
