#ifndef SHYFTDEFINES_SRC_SHYFTDEFINES_H_
#define SHYFTDEFINES_SRC_SHYFTDEFINES_H_

#include "Particle.h"

// Application memory: 128KB
// https://docs.particle.io/datasheets/electron-(cellular)/electron-datasheet/#memory-map-modular-firmware-default-
// This value represents 20% free memory, which is 128 * .2 * 1024 = 26,214.4
const uint32_t FREE_MEM_THRESHOLD = 26214;

// Value of a Null/empty string
#define NULL_STRING "\0" 


/********************************** DEFINITIONS OF millis() TIMER VALUES **********************************/

#define RESET_DELAY (uint16_t)3*1000                        // A 3 seconds delay is allowed before the reset call is attended to
#define RESET_DELAY_90S 90*1000                             // Allow a delay of 90 seconds before reseting the device
#define WATCHDOG_INTERVAL (uint16_t)3*1000                  // Reset the hardware watchdog timer every 3 seconds
#define ONETHOUSAND_MILLIS 1000                             // One Thousand milli seconds
#define GX_10_SECONDS 10*1000                               // 10s interval for attending to timed operations
#define LONG_LOOP_THRESHOLD 2*1000                          // Threshold for checking loop time
#define GEN_METRICS_PUBLISH_INTERVAL 1100                   // Allow 1.1s interval between Gen metrics publishes i.e between MAIN and BASINST

// Run cell tests every 30 minutes, updateable by function and stored in EEPROM
const unsigned long CELL_TEST_PERIOD_DEFAULT = 30*60*1000; 

// millis will rollover at unsigned int max, which is 4294967295 milliseconds
// (roughly 49 days), and our code is not yet implemented with rollover in mind.
// For this and also heap fragmentation reasons, we reset well before (at 7 days
// or 604800000 ms).
const unsigned long MILLIS_RESET_THRESHOLD = 2*24*3600*1000;  // 2 days interval for millis() timer to reset GX
const unsigned long MILLIS_6HRS = 6*3600*1000; // 6 hour interval for checking available storage on the flash partition

// Amount of GX metrics published to the cloud
constexpr uint8_t NUM_OF_GX_METRICS = 4;
/********************************************************************************************************/

/*************** BOUNDARY CONDITIONS FOR CONTROLLING STORAGE AND UTILISATION OF GENCONFIGS **************/

#define MAX_GEN_NAME_LENGTH (uint8_t)5    // Maximum length of the String used for naming a Genset.
#define MIN_GEN_NAME_LENGTH (uint8_t)3    // Minimum length of the String used for naming a Genset.
#define MAX_GEN_SLAVE_ID 247              // Maximum value that can be assigned to the slave ID of a Generator.
#define MIN_GEN_SLAVE_ID (uint8_t)1       // Minimum value that can be assigned to the slave ID of a Generator.
#define MAX_GEN_KVA 350                   // Maximum KVA rating of Generator that can be connected to GX.
#define MIN_GEN_KVA (uint8_t)15           // Minimum KVA rating of Generator that can be connected to GX.
#define TOTAL_BAUDRATES (uint8_t)7        // Total number of Available baudrates.
#define TOTAL_GX_RELAYS (uint8_t)2        // Total number of relays onboard the GX device.
#define NO_GX_RELAYS (uint8_t)0           // Value assigned to a Generator if non of the GX relay is assigned to it.
#define ZERO_INDEX_CORRECTION (uint8_t)1  // Value to be added or subtracted when using a zero indexed object.
#define COMMA_CHAR ','                    // Constant comma(,) character value for processing Strings 
/********************************************************************************************************/

// UFS Configuration Constants
#define MAXIMUM_UFS 4

/************************ DEFINITIONS OF EEPROM ADDRESSES; EEPROM HAS 2047 BYTES ************************/

#define SHYFT_STATE_ADDRESS 0x08 // 512 BYTES
//TODO: Do refactor of SHYFTStateSync.cpp and remove unused EEPROM STORAGE SPACES

//******** EEPROM ADDRESSES FOR GX CONFIGURATIONS ********//
#define EEPROM_ADDR_CRC_VALUE 0x208        // Address for holding computed crc value; 2 BYTES
#define EEPROM_CONFIG_STARTADDR 0x20A      // The start address for all configurations; 124 BYTES
//NEXT EEPROM address to write to is 0x286
/********************************************************************************************************/

/********Data structure that encapsulutes the configuration of any UFS connected to the GX device********/
struct UfsConfig
{
    uint8_t slave_id = UINT8_MAX;                        // Modbus slave ID of UFS
    uint8_t baud_rate = UINT8_MAX;                       // Communication baudrate of the UFS
};

struct MultiUfsConfigs
{
  uint8_t no_of_ufs = 0;
  uint8_t baud_rate = 0;
  uint8_t slave_id[MAXIMUM_UFS];
};
/********************************************************************************************************/

// DATA OUTPUT STRUCTURE FROM A UFS DEVICE
struct UfsDataForm 
{
    double fuel_level = 0.0;
    float temperature = 0.0;
};

#endif // SHYFTDEFINES_SRC_SHYFTDEFINES_H_
