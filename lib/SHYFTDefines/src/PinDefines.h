/**
 * @file    PinDefines.h
 * @author  Toba Adesanya (toba@shyftpower.com)
 * @brief   Header file containing GX Pin definitions
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "GXPrecompilerConfigs.h"

#ifndef SHYFTDEFINES_SRC_PINDEFINES_H_
#define SHYFTDEFINES_SRC_PINDEFINES_H_

#if GX_BORON
// Pin configurations
#define timer_pin D8
#define thermCPL_pin D5
#define PORT_EXPANDER_INIT_PIN D6

#define MODBUS_RTU_DE A4 // Driver output enable pin of RS485 transceiver
#define MODBUS_RTU_RE A5 // Receiver enable input pin of RS485 transceiver

#define VIN_INPUT A1
#define ANALOG_INPUT_1 A2
#define ANALOG_INPUT_2 A0
#define NOR_CS D7

#else

// Pin configurations
#define timer_pin D7
#define thermCPL_pin B5
#define PORT_EXPANDER_INIT_PIN D5

#define MODBUS_RTU_DE A2 // Driver output enable pin of RS485 transceiver
#define MODBUS_RTU_RE A1 // Receiver enable input pin of RS485 transceiver

#define VIN_INPUT A5
#define ANALOG_INPUT_1 A4
#define ANALOG_INPUT_2 DAC1
#define NOR_CS D6

#endif

/* LED switching Macros (1 - ON, 0 - OFF)*/
#define LED1_pin 11
#define LED2_pin 10
#define LED3_pin 9
#define LED1(_state) (_state) ? portExpander.digitalWrite(LED1_pin, HIGH) : portExpander.digitalWrite(LED1_pin, LOW)
#define LED2(_state) (_state) ? portExpander.digitalWrite(LED2_pin, HIGH) : portExpander.digitalWrite(LED2_pin, LOW)
#define LED3(_state) (_state) ? portExpander.digitalWrite(LED3_pin, HIGH) : portExpander.digitalWrite(LED3_pin, LOW)

// Relay switching Macros (1 - ON, 0 - OFF)
#define RLY1_pin 7
#define RLY2_pin 6
#define RLY1(_state) (_state) ? portExpander.digitalWrite(RLY1_pin, HIGH) : portExpander.digitalWrite(RLY1_pin, LOW)
#define RLY2(_state) (_state) ? portExpander.digitalWrite(RLY2_pin, HIGH) : portExpander.digitalWrite(RLY2_pin, LOW)

// Binary inputs
#define D_IN1 15
#define D_IN2 14
#define D_IN3 13
#define D_IN4 12

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF 430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL 100.0

#endif // SHYFTDEFINES_SRC_PINDEFINES_H_
