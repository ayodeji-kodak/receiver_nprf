#include <SPI.h> // for SPI communication

#include <nRF24L01.h>

#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

int value1;
int value2;

const uint64_t pipe = 0xE8E8F0F0E1LL; // the address the the module

void setup() {

  Serial.begin(9600);

  radio.begin();

  radio.openReadingPipe(1, pipe);

  radio.setPALevel(RF24_PA_MAX);

  radio.startListening();

}

void loop() {

  if (radio.available()) { // if nrf has any incoming data

    radio.read(&value1, sizeof(value1));
    radio.read(&value2, sizeof(value2));

    Serial.println(value1, value2);

  }
}
