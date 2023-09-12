#ifndef SHYFTDEFINES_SRC_HIRESSENSORREADING_H_
#define SHYFTDEFINES_SRC_HIRESSENSORREADING_H_
  
#include "Particle.h"
#include "SHYFTDefines.h"

#define NUM_OF_SAMPLES 10
#define MAXIMUM_FLD 4      // Maximum fuel-level data source

struct HiResSensorReading
{
  unsigned int ts[NUM_OF_SAMPLES] = {0};                    // Timestamp (in seconds) for reading time
  double fuelLevel[NUM_OF_SAMPLES] = {0}; // Fuel level (in percentage) remaining in building's generator at interval end
  double ufs_fuelLevel[NUM_OF_SAMPLES] = {0};               // Fuel level (in inches) remaining in building's generator
  float ufs_temp[NUM_OF_SAMPLES] = {0};                     // UFS temperature (in celcius) 
  double voltage[NUM_OF_SAMPLES] = {0};         // System voltage at interval end
  float pyr_value[NUM_OF_SAMPLES] = {0};      // pyranometer sensor readings
  float thermcpl_RTD[NUM_OF_SAMPLES] = {0};
  float res_sensor[NUM_OF_SAMPLES] = {0};
  UfsDataForm ufsData[NUM_OF_SAMPLES][MAXIMUM_FLD];
  bool bin_input4 = true, bin_input3 = true, bin_input2 = true, bin_input1 = true;
};

#endif // SHYFTDEFINES_SRC_HIRESSENSORREADING_H_
