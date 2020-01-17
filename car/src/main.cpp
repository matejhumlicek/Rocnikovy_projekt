#include <Arduino.h>
#include <AFMotor.h>
AF_DCMotor motorR(2);
AF_DCMotor motorL(1);
char data = 0;
char speed = 145;
void setup()
{
    Serial.begin(9600);                               
   // Serial.println("TEST");
    motorR.setSpeed(speed);
    motorL.setSpeed(speed);
}
void forward()
{
  Serial.println("DOPREDU");  
  motorR.run(BACKWARD);
  motorL.run(BACKWARD);
}
void right()
{
  Serial.println("ZPATKY");  
  motorR.run(BACKWARD);
  motorL.run(FORWARD);
}
void left()
{
  Serial.println("VLEVO");  
  motorR.run(FORWARD);
  motorL.run(BACKWARD);
}
void backward()
{
  Serial.println("VPRAVO");  
  motorR.run(FORWARD);
  motorL.run(FORWARD);
}
void hold()
{
  Serial.println("Stop"); 
  motorR.run(RELEASE);
  motorL.run(RELEASE);
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

