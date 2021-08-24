#include <SoftwareSerial.h>

#define serial4_TX A8
#define serial4_RX A9
#define serial5_TX A10
#define serial5_RX A11

SoftwareSerial Serial4(serial4_RX, serial4_TX);
SoftwareSerial Serial5(serial5_RX, serial5_TX);

void setup() 
{
  Serial2.begin(9600);
  Serial1.begin(9600);
  Serial3.begin(9600);
  Serial4.begin(9600);
  Serial5.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
   char c, x;
   int counter = 0;
   if(Serial.available())
   {
      c = Serial.read();
      
      if(c == '\r' || c == '\n')
      {
         //do nothing
      }
      else
      {
         Serial.println(c);
         if (c == '1')
         {
            Serial1.print(c);
            while(!Serial2.available() && counter < 10)
            {
               delay(20);
               counter++;
            }
            if(counter < 10)
            {
                x = Serial2.read();
                Serial.print("Data from Serial1 successfully sent to Serial2: ");
                Serial.println(x);
            }
            else
            {
                Serial.println("Data from Serial1 FAIL to send to Serial2");
            }
         }
         else if (c == '2')
         {
            Serial2.print(c);
            while(!Serial1.available() && counter < 10)
            {
               delay(20);
               counter++;
            }
            if(counter < 10)
            {
                x = Serial1.read();
                Serial.print("Data from Serial2 successfully sent to Serial1: ");
                Serial.println(x);
            }
            else
            {
                Serial.println("Data from Serial2 FAIL to send to Serial1");
            }
         }
         else if (c == '3')
         {
            Serial4.listen();
            Serial3.print(c);
            while(!Serial4.available() && counter < 10)
            {
               delay(20);
               counter++;
            }
            if(counter < 10)
            {
                x = Serial4.read();
                Serial.print("Data from Serial3 successfully sent to Serial4: ");
                Serial.println(x);
            }
            else
            {
                Serial.println("Data from Serial3 FAIL to send to Serial4");
            }
         }
         else if (c == '4')
         {
            Serial4.print(c);
            while(!Serial3.available() && counter < 10)
            {
               delay(20);
               counter++;
            }
            if(counter < 10)
            {
                x = Serial3.read();
                Serial.print("Data from Serial4 successfully sent to Serial3: ");
                Serial.println(x);
            }
            else
            {
                Serial.println("Data from Serial4 FAIL to send to Serial3");
            }
         }
         else if (c == '5')
         {  
            Serial5.print(c);
            while(!Serial3.available() && counter < 10)
            {
               delay(20);
               counter++;
            }
            if(counter < 10)
            {
                x = Serial3.read();
                Serial.print("Data from Serial5 successfully sent to Serial3: ");
                Serial.println(x);
            }
            else
            {
                Serial.println("Data from Serial5 FAIL to send to Serial3");
            }
         }
         else if (c == '6')
         {  
            Serial5.listen();
            Serial3.print(c);
            while(!Serial5.available() && counter < 10)
            {
               delay(20);
               counter++;
            }
            if(counter < 10)
            {
                x = Serial5.read();
                Serial.print("Data from Serial3 successfully sent to Serial5: ");
                Serial.println(x);
            }
            else
            {
                Serial.println("Data from Serial3 FAIL to send to Serial5");
            }
         }
      }
   }
   delay(20);
}
