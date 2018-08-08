#include <Arduino.h>
#include <Wire.h>
#define SLAVE_ADDRESS 0x08

int recvByte = 0;
int state = 0;

void receiveData(int byteCount){
  while(Wire.available()) {
    recvByte = Wire.read();
    Serial.print("Data received: ");
    Serial.println(recvByte);
    if (state == 0){
      digitalWrite(13, HIGH); // set the LED on
      state = 1;
      }
    else{
      digitalWrite(13, LOW); // set the LED off
      state = 0;
      }
  }
}

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600); // start serial for output
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);

  Serial.println("Ready!");
}

void loop() {
  delay(100);
}