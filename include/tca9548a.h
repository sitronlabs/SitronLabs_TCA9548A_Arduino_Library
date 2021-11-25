#ifndef TCA9548A_H
#define TCA9548A_H

/* Arduino libraries */
#include <Arduino.h>
#include <Wire.h>

/* C/C++ libraries */
#include <errno.h>
#include <stdint.h>

/**
 * 
 */
class tca9548a {

   public:
    int setup(TwoWire& i2c_library, const uint8_t i2c_address);
    int channel_select(const uint8_t index);

   protected:
    TwoWire* m_i2c_library = NULL;
    uint8_t m_i2c_address;
};

#endif
