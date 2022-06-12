#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 8); // CE, CSN 8 10
const byte address[6] = "00001";
struct Data {
  int potVal;
};

Data data;


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  
  if (radio.available()) {
    radio.read(&data, sizeof(Data));
    Serial.println(data.potVal);
  }
}
