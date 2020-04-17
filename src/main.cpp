#include <Arduino.h>
#include <Servo.h>
Servo servo;
int servoPin=9;
int step_time=500;
int leftButtonPin = 8;
int rightButtonPin = 7;
int step_deg = 10;

int serva_position = 0;
void setup() 
{
 servo.attach(servoPin);
 servo.write(serva_position);
 pinMode(leftButtonPin, INPUT); 
}
void loop() 
{
   if ((digitalRead(leftButtonPin)==HIGH)&&serva_position!=180) 
      {      
        serva_position = serva_position+step_deg;
        servo.write(serva_position);
        delay(step_time);
      }
 if ((digitalRead(rightButtonPin)==HIGH)) 
      {      
        serva_position =0;
        servo.write(serva_position);
        delay(500);
      }
}
 