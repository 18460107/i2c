#include <Wire.h>
#include "SparkFunHTU21D.h"
char rec;
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

//Create an instance of the object
HTU21D myHumidity;

void setup()
{
  Serial.begin(9600);
  inputString.reserve(200);

  myHumidity.begin();
}

void loop()
{

  float humd = myHumidity.readHumidity();
  int temp = myHumidity.readTemperature();
  if (stringComplete) {

    ////////////DIRECCION 1
    if(inputString == "1_"){
      
        Serial.print(temp);
        
}

  /*Serial.print(millis());
  Serial.print(" Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");

  Serial.println();
  delay(1000);*/
   inputString = "";
    stringComplete = false;
  }
}
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '_') {
      stringComplete = true;
    }
  }
}
