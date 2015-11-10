#ifndef I2C_EEPROM_H
#define I2C_EEPROM_H

#include "Arduino.h"
#include <Wire.h>



class i2c_eeprom
{
  public:
    i2c_eeprom(int inDeviceAddress);
    void write(unsigned int inEEAddress, byte inData);
    byte read(unsigned int inEEAddress);
    void update(unsigned int inEEAddress, byte inData);
    
  private:
    int _deviceAddress;
};

#endif
