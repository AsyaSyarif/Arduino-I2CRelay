#ifndef PortExpander_I2C_h
#define PortExpander_I2C_h

#include <Wire.h>


class I2CRelay {
	public:
		I2CRelay(uint8_t lcd_Addr);
		void init();
  		void pinMode( uint8_t port, uint8_t mode );
  		void digitalWrite( uint8_t port, uint8_t level );
  		void digitalWriteAll( uint8_t levels );
  		uint8_t digitalRead( uint8_t port );
  		uint8_t digitalReadAll();

	private:
  		void init_priv();
  		void i2cWrite(uint8_t);
  		uint8_t _Addr;
  		uint8_t _portValues;
};

#endif