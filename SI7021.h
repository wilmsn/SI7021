/*
  A temperature and humidity sensor for Arduino
*/
#ifndef _SI7021_h
#define _SI7021_h

#include "Arduino.h"
#include <Wire.h>

class SI7021 {
 private:
	uint8_t si7021_i2c_address = 0x40;  // I2C address (ADD=L=0100011)

 public:
 
 SI7021(void);
 
 SI7021(uint8_t I2Caddress);
 
  /**
   * Begin operation of the chip
   * 
   * Call this in setup(), before calling any other methods.
   */
  void begin(void);

  /**
   * Reads Values from the chip
   * 
   * Call one of this functions to get the values.
   */

  float readTemperature(void);   

  float readHumidity(void);   
  
};  

#endif
