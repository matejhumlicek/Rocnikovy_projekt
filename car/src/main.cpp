
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




