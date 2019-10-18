#include <I2CRelay.h>

#define address_relay 	0x20 //untuk mengetahui address, jalankan I2CScanner terdahulu
#define totalOutputs 	7    //Total output relay yang terpasang

I2CRelay myRelay(address_relay); //Panggil Object dengan sebutan myRelay
int ch[] =  {0,1,2,3,4,5,6,7};  

void setup() {
  myRelay.init(); //Insialisasi
  
  for (int i = 0; i < totalOutputs; i++){
    pinMode(ch[i], OUTPUT);
  }
  
}

void loop() {
	
	//Untuk melakukan test pada keseluruhan channel
	//relay akan menyala bergantian
	
  for (int i=0; i< totalOutputs; i++){
    myRelay.digitalWrite(ch[i], HIGH);
    delay(500);
    myRelay.digitalWrite(ch[i], LOW);
   }

   for (int i = totalOutputs - 1; i >= 0; i-- ){
	 myRelay.digitalWrite(ch[i], HIGH);
	 delay(500);
	 myRelay.digitalWrite(ch[i], LOW);
	}
  
}
