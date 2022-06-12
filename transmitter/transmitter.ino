//Transmitter Code
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); // CE, CSN 9 8

struct Data {
  int potVal;
};

Data data;
const byte address[6] = "00001";


void setup() {
  pinMode(A3, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {

  data.potVal = map(analogRead(A3), 335, 1023, 0, 255);
  Serial.println(data.potVal);
  radio.write(&data, sizeof(Data));
  Serial.println("Transmission Done!");
}
