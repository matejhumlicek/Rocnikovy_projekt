//This program is used to control a robot car or similar using a app that communicates with Arduino through a bluetooth module

#include <Arduino.h>
#include <AFMotor.h>
//creates two objects to control two terminals on the motor shield 
AF_DCMotor motor1(2,MOTOR12_1KHZ); 
AF_DCMotor motor2(1,MOTOR12_1KHZ); 

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stopped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
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
  motor1.setSpeed(220); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor clockwise
  motor2.setSpeed(220); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(220); 
  motor1.run(FORWARD); //rotate the motor counterclockwise
  motor2.setSpeed(220); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
}

void left()
{
  motor1.setSpeed(220); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(100);
  motor2.run(FORWARD); //turn motor2 off
}

void right()
{
  motor1.setSpeed(100);
  motor1.run(FORWARD); //turn motor1 off
  motor2.setSpeed(220); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}
