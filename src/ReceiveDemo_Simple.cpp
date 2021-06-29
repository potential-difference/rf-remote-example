/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>
#include <Arduino.h>

RCSwitch rcSwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  rcSwitch.enableReceive(2);  // receiver pin number!
}

char *remote_array[2];

void loop() {
  if (rcSwitch.available()) {
    
    Serial.print("Received ");
    Serial.printf( "%#lx",rcSwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( rcSwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( rcSwitch.getReceivedProtocol() );

    rcSwitch.resetAvailable();
  }
}
