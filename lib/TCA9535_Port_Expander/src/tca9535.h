/*
 * tca9535.h
 *
 *  Created on: Jan 17, 2018
 *      Author: curt
 */

#ifndef APP_LIB_TCA9535_H_
#define APP_LIB_TCA9535_H_

#include <Particle.h>

class TCA9535 {
    public:
        bool begin(void);
        bool pinMode(uint16_t pin, PinMode setMode);
        bool digitalWrite(uint16_t pin, bool value);
        bool digitalRead(uint16_t pin, bool * value);
    private:
        bool read(byte reg, byte * value);
        bool write(byte reg, byte value);
        bool readModifyWrite(byte reg, byte dataMask, byte pinMask);
};

#endif /* APP_LIB_TCA9535_H_ */
