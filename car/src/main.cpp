

#include <Arduino.h>
#include <AFMotor.h>
AF_DCMotor motor1(2,MOTOR12_1KHZ); 
AF_DCMotor motor2(1,MOTOR12_1KHZ); 

char command; 

void setup() 
{       
  Serial.begin(9600); 
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop();    
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
     default:
      Stop();
      break;
    }
  } 
}

void forward()
{
  motor1.setSpeed(220); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(220);
  motor2.run(FORWARD); 
}

void back()
{
  motor1.setSpeed(220); 
  motor1.run(FORWARD); 
  motor2.setSpeed(220); 
  motor2.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(220); 
  motor1.run(FORWARD); 
  motor2.setSpeed(100);
  motor2.run(FORWARD); 
}

void right()
{
  motor1.setSpeed(100);
  motor1.run(FORWARD); 
  motor2.setSpeed(220); 
  motor2.run(FORWARD); 
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); 
  motor2.setSpeed(0);
  motor2.run(RELEASE); 
}

