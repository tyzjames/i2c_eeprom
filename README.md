# i2c_eeprom
Using the Atmel 24C256 EEPROM chip with Arduino

This library implements the wire library to allow Arduino to work with the Atmel 24C256 EEPROM chip. 

<h2> Steps </h2>
- Connect the EEPROM chip to your Arduino as follows
Arduino Pin|EEPROM Pin|Description
---|---|---
|1,2,3,4,7| Ground
A4|5|
A5|6|
+5v|8|

- Initialize the library with the chip address
```c++
i2c_eerpom ee(0x50);
```

<h3> read(unsigned int eepromAddress) </h3>
<h3> write(unsigned int eepromAddress, byte inData) </h3>
<h3> update(unsigned int eepromAddress, byte inData) </h3>
