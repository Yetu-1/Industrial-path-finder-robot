/*
 * TCA9535 Port Expander Library
 * The 9535 consists of 2 ports, 8 pins each.
 *
 * The API uses pin 0 - 15 where:
 *  0-7 is Port1 pins
 *  8-15 is Port2 pins
 */

#include "tca9535.h"
#include <stdint.h>

#define I2C_ADDRESS                 (0x20)

#define TCA9535_REG_INPUT_PORT1     (0x00)
#define TCA9535_REG_INPUT_PORT2     (0x01)
#define TCA9535_REG_OUTPUT_PORT1    (0x02)
#define TCA9535_REG_OUTPUT_PORT2    (0x03)
#define TCA9535_REG_POLARITY_PORT1  (0x04)
#define TCA9535_REG_POLARITY_PORT2  (0x05)
#define TCA9535_REG_CONFIG_PORT1    (0x06)
#define TCA9535_REG_CONFIG_PORT2    (0x07)

#define TCA9535_MAX_PIN             (15)

#define BITMASK_PIN(pin_)           ((pin_) < 8) ? 1 << (pin_) : 1 << ((pin_) - 8)
#define BITMASK_DATA(pin_, bool_)   ((pin_) < 8) ? (bool_) << (pin_) : (bool_) << ((pin_) - 8)

#define REG_INPUT(pin_)             ((pin_) < 8) ? TCA9535_REG_INPUT_PORT1 : TCA9535_REG_INPUT_PORT2
#define REG_OUTPUT(pin_)            ((pin_) < 8) ? TCA9535_REG_OUTPUT_PORT1 : TCA9535_REG_OUTPUT_PORT2
#define REG_POLARITY(pin_)          ((pin_) < 8) ? TCA9535_REG_POLARITY_PORT1 : TCA9535_REG_POLARITY_PORT2
#define REG_CONFIG(pin_)            ((pin_) < 8) ? TCA9535_REG_CONFIG_PORT1 : TCA9535_REG_CONFIG_PORT2


bool TCA9535::begin(void) {
    // Attempt a read of the chip to verify comms

    if (!Wire.isEnabled()) {
      Wire.begin();
    }

    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write(TCA9535_REG_INPUT_PORT1);
    byte result = Wire.endTransmission(true);
    if (0 != result) {
        // Failed to talk to TCA chip
        return false;
    }
    return true;
}

bool TCA9535::read(byte reg, byte * value) {
    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write(reg);
    if (0 != Wire.endTransmission())
        return false;

    Wire.requestFrom(I2C_ADDRESS, 1);
    *value = Wire.read();
    return true;
}

bool TCA9535::write(byte reg, byte value) {
    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write(reg);
    Wire.write(value);
    if (0 != Wire.endTransmission())
        return false;
    return true;
}

bool TCA9535::readModifyWrite(byte reg, byte dataMask, byte pinMask) {
    byte value;

    if (false == this->read(reg, &value))
        return false;

    value &= ~pinMask;  //clear bit
    value |= dataMask;

    if (false == this->write(reg, value))
        return false;

    return true;
}

bool TCA9535::pinMode(uint16_t pin, PinMode setMode) {
    bool dir = false;
    byte reg, mask, data;

    if (pin > TCA9535_MAX_PIN) {
        // ASSERT
        return false;
    }

    if (INPUT == setMode) {
        dir = true;
    }

    reg = REG_CONFIG(pin);
    mask = BITMASK_PIN(pin);
    data = BITMASK_DATA(pin, dir);

    return this->readModifyWrite(reg, data, mask);
}

bool TCA9535::digitalWrite(uint16_t pin, bool value) {
    byte reg, mask, data;

    if (pin > TCA9535_MAX_PIN) {
        // ASSERT
        return false;
    }

    reg = REG_OUTPUT(pin);
    mask = BITMASK_PIN(pin);
    data = BITMASK_DATA(pin, value);

    return this->readModifyWrite(reg, data, mask);
}

bool TCA9535::digitalRead(uint16_t pin, bool * value) {
    byte reg, mask, regValue;

    if (pin > TCA9535_MAX_PIN) {
        // ASSERT
        return false;
    }

    reg = REG_INPUT(pin);
    mask = BITMASK_PIN(pin);

    if (false == this->read(reg, &regValue))
        return false;

    if (mask & regValue) {
        *value = true;
    }
    else {
        *value = false;
    }
    return true;
}
