#include <Arduino.h>
#include <Servo.h>
#include "main.h"
int leftButtonPin = 8;
int rightButtonPin = 7;

Servo servo;
int servoPin=9;
int step_time=500;
int step_deg = 10; // angle of rotatiom
int numbMicroStep =10; //for smooth rotation

int serva_position;

void setup() 
{

}
void loop() 
{
   if ((digitalRead(leftButtonPin)==HIGH)&&serva_position!=180) 
      { 
          serva_position = clockwiseMove();
      }
 if ((digitalRead(rightButtonPin)==HIGH)&&serva_position!=0) 
      { 
          serva_position = counterClockwiseMove();
      }
}
int clockwiseMove(){
        servo.attach(servoPin); //Servo in on
         for (int x = 0; x < numbMicroStep; x++){
          serva_position = serva_position+step_deg/numbMicroStep;
          servo.write(serva_position);
          delay(step_time/numbMicroStep);
         }      

        servo.detach(); //Servo is off
        return serva_position;
        }

int counterClockwiseMove(){
          servo.attach(servoPin);
            for (int x = 0; x < numbMicroStep; x++){
              serva_position = serva_position-step_deg/numbMicroStep;
              servo.write(serva_position);
              delay(step_time/numbMicroStep);
         }      

        servo.detach(); 
        return serva_position;
        }