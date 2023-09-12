#ifndef SHYFTDEFINES_SRC_INTERVALDEFINITIONS_H_
#define SHYFTDEFINES_SRC_INTERVALDEFINITIONS_H_

#include "Particle.h"
#include "EnumDefinitions.h"
#include "ResetReasons.h"
#include "SourceChangeDefinitions.h"

/**
 * @brief Data Structure used to store energy data collected 
 *        for every 15 minute interval
 * 
 */
struct Interval
{
  unsigned int ts;    // timestamp for interval end
  float gridWh;       // Wh of energy used from grid during interval
  float genWh;        // Wh of energy used from gen during interval
  float peakW;        // peak power drawn during interval, as kW
  float solarWh;      // Wh of energy produced by solar during interval
  uint8_t batterySoC; //%SoC of building's battery bank at interval end
  uint8_t fuelLevel;  //% fuel level remaining in building's generator at interval end
  int voltage;        // system voltage at interval end

  uint8_t percent;
}; // uses ~32bytes/Interval

const unsigned int SEND_INTERVAL = 900;

/**
 * @brief Data Structure used to store the state of SHYFT, updated in EEPROM after any
 *        changes, and retrieved from EEPROM at start up to reset state correctly
 * 
 */
struct SHYFTState
{
  uint8_t version;
  unsigned int source_ts; // ts of last source change
  PowerSource source;     // 0 -> off, 1 -> grid, 2 -> gen
  bool autoMode;          // true -> on, false -> off

  // Information about partial data interval
  unsigned int intervalEnd; // timestamp for interval end
  float partGridWh;         // Wh of energy used from grid so far in interval
  float partGenWh;          // Wh of energy used from gen so far in interval
  float partPeakW;          // peak power drawn so far in interval, as kW
  float partSolarWh;        // Wh of energy produced by solar so far in interval

  // NOTE: these, so far, are uninitialized. This means that they will
  // probably get sent in the interval as 255 (since uint8_t and EEPROM).
  // So, we should just be aware of that.
  int lastBatterySoC;
  uint8_t lastFuelLevel;
  uint8_t lastVoltage;

  unsigned int lastUpdated;
  unsigned int missedSeconds;

  TimerType activeTimerType;

  Reset::Reason lastResetReason;

  SourceChange::State sourceChangeState;
};

struct IntervalTestResult
{
  bool addressesOutOfSync;
  uint32_t EEPROMNextSaveAddress;
  uint32_t flashNextSaveAddress;
  uint8_t statusOfIntervalAtEEPROMAddress; // 0 = nothing, 1 = full, 2 = gibberish
  uint8_t statusOfIntervalAtFlashAddress;
  uint8_t lastFlashError;
};

#endif // SHYFTDEFINES_SRC_INTERVALDEFINITIONS_H_
