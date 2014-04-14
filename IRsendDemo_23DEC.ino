/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
   pinMode(9,OUTPUT); // The library initializes pin 3 as an output
  digitalWrite(9, LOW);// Since our LED is connected to pin 9, we initialize it here
}

void loop() {
  if (Serial.read() != -1) {
    for (int i = 0; i < 3; i++) {
      //irsend.sendSony(0xa90, 12); // Sony TV power code
      
      irsend.sendNEC(0x99E21D,32);
      Serial.print("Sent code ");
      Serial.print(i);
      Serial.println("\n");
      
      delay(1000);
    }
  }
}
