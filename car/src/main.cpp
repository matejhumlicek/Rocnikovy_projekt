
#include <Arduino.h>
#include <AFMotor.h>
AF_DCMotor motorR(2);
AF_DCMotor motorL(1);
char data = 0;
void setup()
{
    Serial.begin(9600);                               
    Serial.println("Motor test !");
    motorR.setSpeed(245);
    motorL.setSpeed(245);
}
void forward()
{
  Serial.println("DOPREDU");
  
  motorR.run(BACKWARD);
  motorL.run(FORWARD);
}
void backward()
{
  Serial.println("ZPATKY");
  
  motorR.run(FORWARD);
  motorL.run(BACKWARD);
}
void left()
{
  Serial.println("VLEVO");
  
  motorR.run(BACKWARD);
  motorL.run(RELEASE);
}
void right()
{
  Serial.println("VPRAVO");
  
  motorR.run(RELEASE);
  motorL.run(FORWARD);
}
void hold()
{
  Serial.println("Stop");
 
  motorR.run(RELEASE);
  motorL.run(RELEASE);
}
void spinRight()
{
  Serial.println("TOCENI DOPRAVA");
  delay(500);
  motorR.run(FORWARD);
  motorL.run(FORWARD);
}
void spinLeft()
{
  Serial.println("TOCENI DOLEVA ");
  delay(500);
  motorR.run(BACKWARD);
  motorL.run(BACKWARD);
}
void loop()
{
   if(Serial.available() > 0)  
   {
      data = Serial.read(); 
      Serial.println(data);
                
      if(data == 'F')
      {
        forward();
      }
      else if(data == 'B')
      {
        backward();
      }
      else if(data == 'R')
      {
        right();
      }
      else if(data == 'L')
      {
        left();
      }
      else if(data == 'S')
      {
        hold();
      }
   }
 }




/*#include <Arduino.h>
#include <AFMotor.h>
#include <SoftwareSerial.h>
AF_DCMotor motor1(2,MOTOR12_1KHZ); 
AF_DCMotor motor2(1,MOTOR12_1KHZ); 
char t; 
void setup() 
{       
  Serial.begin(9600); 
}
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  motor1.setSpeed(220); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(220);
  motor2.run(FORWARD);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  motor1.setSpeed(220); 
  motor1.run(FORWARD); 
  motor2.setSpeed(220); 
  motor2.run(BACKWARD); 
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
 motor1.setSpeed(220); 
  motor1.run(FORWARD); 
  motor2.setSpeed(100);
  motor2.run(FORWARD); 
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  motor1.setSpeed(100);
  motor1.run(FORWARD); 
  motor2.setSpeed(220); 
  motor2.run(FORWARD); 
}
 
else if(t == 'S'){      //STOP (all motors stop)
  motor1.setSpeed(0);
  motor2.run(RELEASE); 
  motor2.setSpeed(0);
  motor2.run(RELEASE); 
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
*/
