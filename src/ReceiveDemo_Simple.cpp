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
    
    int buttonValue = int( rcSwitch.getReceivedValue() & 0xff );

    Serial.print("Received ");
    Serial.printf( "%#lx",rcSwitch.getReceivedValue() );
    Serial.print(" Button Value ");
    Serial.print( buttonValue);
    Serial.print(" / ");
    Serial.print( rcSwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( rcSwitch.getReceivedProtocol() );

    rcSwitch.resetAvailable();

    switch (buttonValue)
    {
    case 10:
      Serial.print("red");
      break;
      case 11:
      Serial.print("green");
    break;
    case 12:
    Serial.print("blue");
    break;
    default:
      break;
    }
  }
}
