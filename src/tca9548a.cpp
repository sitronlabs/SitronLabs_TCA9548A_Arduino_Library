/* Self header */
#include "tca9548a.h"

/* Arduino libraries */
#include <Wire.h>

/**
 * 
 */
int tca9548a::setup(TwoWire& i2c_library, const uint8_t i2c_address) {
    if ((i2c_address & 0xF8) != 0x70) {
        return -EINVAL;
    }
    m_i2c_library = &i2c_library;
    m_i2c_address = i2c_address;
    return 0;
}

/**
 * 
 */
int tca9548a::channel_select(const uint8_t index) {
    if (m_i2c_library == NULL) {
        return -EINVAL;
    }
    if (index > 7) {
        return -EINVAL;
    }
    m_i2c_library->beginTransmission(m_i2c_address);
    if (m_i2c_library->write(1 << index) != 1) {
        return -EIO;
    }
    if (m_i2c_library->endTransmission(true) != 0) {
        return -EIO;
    }
    return 0;
}