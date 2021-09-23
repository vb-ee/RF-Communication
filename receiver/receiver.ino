#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8);

const uint64_t address = 0xF0F0F0F0E1LL;
char data;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop() {
  if ( radio.available() ) {
    radio.read(&data, sizeof(data));
    Serial.println(data);
  }
}
