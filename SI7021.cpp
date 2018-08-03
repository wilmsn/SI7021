/*
  SI7021.cpp - Library for SI7021 Chip.
  Created by Norbert Wilms, July, 4, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SI7021.h"

SI7021::SI7021(void) {
	
}

SI7021::SI7021(uint8_t I2Caddress) {
	si7021_i2c_address = I2Caddress;
}

void SI7021::begin() {
	Wire.begin();
	Wire.beginTransmission(si7021_i2c_address);             // I2C address
	Wire.endTransmission();
}

float SI7021::readTemperature() {
  uint8_t raw0,raw1;
  uint16_t temp_code;
  float temperature;

	Wire.beginTransmission(si7021_i2c_address);             // I2C address
	Wire.write(0xE3);
	Wire.endTransmission();
	Wire.requestFrom(si7021_i2c_address,(uint8_t)2);
 
	if(Wire.available()<=2) {
		raw0 = Wire.read();
		raw1 = Wire.read();
		temp_code = raw0;
		temp_code = temp_code<<8;
		temp_code = temp_code + raw1;
		temperature = ((float)temp_code/65536.0*175.72) - 46.85;                        
	} else {
		temperature = -999;                        
	}
	return temperature;
}

float SI7021::readHumidity() {
  uint16_t rh_code;
  uint8_t raw0, raw1;
  float humidity;

	Wire.beginTransmission(si7021_i2c_address);             // I2C address
	Wire.write(0xE5);
	Wire.endTransmission();
	Wire.requestFrom(si7021_i2c_address,(uint8_t)2);
 
	if(Wire.available()<=2) {
		raw0 = Wire.read();
		raw1 = Wire.read();
		rh_code = raw0;
		rh_code = rh_code<<8;
		rh_code = rh_code + raw1;
		humidity = ((float)rh_code / 65536.0 * 125) - 6.0;
	} else {
		humidity = -999;
	}
	return humidity;
}
