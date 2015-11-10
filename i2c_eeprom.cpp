#include "Arduino.h"
#include "i2c_eeprom.h"

i2c_eeprom::i2c_eeprom(int inDeviceAddress) {
  this->_deviceAddress = inDeviceAddress;
  Wire.begin();
}

void i2c_eeprom::write(unsigned int inEEAddress, byte inData) {
    int rdata = inData;
    Wire.beginTransmission(this->_deviceAddress);
    Wire.write((int)(inEEAddress >> 8)); // MSB
    Wire.write((int)(inEEAddress & 0xFF)); // LSB
    Wire.write(rdata);
    Wire.endTransmission();
}

byte i2c_eeprom::read(unsigned int inEEAddress) {
    byte rdata = 0xFF;
    Wire.beginTransmission(this->_deviceAddress);
    Wire.write((int)(inEEAddress >> 8)); // MSB
    Wire.write((int)(inEEAddress & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(this->_deviceAddress,1);
    if (Wire.available()) rdata = Wire.read();

    return rdata;
}

void i2c_eeprom::update(unsigned int inEEAddress, byte inData) {
  byte rdata = this->read(inEEAddress);
  if (inData != rdata) {
    this->write(inEEAddress, inData);
  }
}
