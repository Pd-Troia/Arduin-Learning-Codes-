#include "BluetoothSerial.h"

BluetoothSerial serialBT;

void setup() {
  serialBT.begin("ESP-32");
  Serial.begin(115200);
  pinMode(2,OUTPUT);
}

void loop() {
  if(serialBT.available()){
    char ch = serialBT.read();    
    if(ch == '1'){
      digitalWrite(2,1);
    }
    if(ch == '2'){
      digitalWrite(2,0);
    }
  }
  delay(20);
}
