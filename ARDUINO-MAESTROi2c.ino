#include <SoftwareSerial.h>
#define DEBUG(a) Serial.println(a);

char var;
char svar;
int data;
int x;
SoftwareSerial Serial_2(2,3);

void setup() {
  Serial.begin(9600);
  Serial_2.begin(9600);
}

void loop() {
  if(Serial.available()){
    var=Serial.read();
    
    
    if(var=='1'){
      Serial_2.print("1_");
      }
    if(var=='0'){
      Serial.print(x);
      }
    delay(50);
    data = Serial_2.parseInt();
    DEBUG((int)data);
    x=data;
    

}
}
