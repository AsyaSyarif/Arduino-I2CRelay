//Bandung 2017 @arif
#include "I2CRelay.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


I2CRelay::	I2CRelay(uint8_t i2c_addr){
	_Addr = i2c_addr;
}

void I2CRelay::init(){
	init_priv();
}

void I2CRelay::init_priv(){
	_portValues = 0x00;
	Wire.begin();
    digitalWriteAll(0x00);
}

void I2CRelay::digitalWrite(uint8_t port, uint8_t level){
	if( level == LOW ){ 
        _portValues &= ~(1 << port);
    } else { 
        _portValues |= (0x01 << port);
    }
	i2cWrite(_portValues);  
}

void I2CRelay::digitalWriteAll(uint8_t levels){
	_portValues = levels;
	i2cWrite(_portValues);
}


void I2CRelay::pinMode(uint8_t port, uint8_t mode){
	if( mode == INPUT ){
        digitalWrite(port, HIGH);
    }
}

uint8_t I2CRelay::digitalReadAll(){
	Wire.requestFrom(_Addr,(uint8_t)1);
    uint8_t resp = Wire.read();
    return resp;
}

void I2CRelay::i2cWrite(uint8_t _data){
	Wire.beginTransmission(_Addr);
    Wire.write(_data);
	Wire.endTransmission();  
}
