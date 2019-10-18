#include <I2CRelay.h>

#define address_relay 	0x20 	 //untuk mengetahui address, jalankan I2CScanner terdahulu
I2CRelay myRelay(address_relay); //Panggil Object dengan sebutan myRelay

void setup() {
  myRelay.init();
}

void loop() {
  //Sebagai contoh simple, saya akan menyalakan channel 0 
  myRelay.digitalWrite(0, HIGH);
  delay(1000);
  myRelay.digitalWrite(0, LOW);
  delay(1000);
}
