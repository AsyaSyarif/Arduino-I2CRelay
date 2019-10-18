#include <Wire.h>

#define BAUDRATE 115200
 
void setup(){
  Wire.begin();
  Serial.begin(BAUDRATE);
  while (!Serial); // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}


void loop(){
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ){

    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0){
      Serial.print("I2C ditemukan pada address 0x");
      if (address<16) 
      Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    } else if (error==4) {
      Serial.print("error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  
  if (nDevices == 0)
    Serial.println("Module dengan I2C tidak ditemukan! \n");
  else
    Serial.println("done\n");

  delay(2000); // delay 2 detik untuk proses scanning berikutnya
  
}