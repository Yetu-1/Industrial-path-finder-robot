#ifndef SHYFTDEFINES_SRC_GENERATORDEFINITIONS_H_
#define SHYFTDEFINES_SRC_GENERATORDEFINITIONS_H_

#include "Particle.h"
#include "SHYFTDefines.h"

//******** DEFINITIONS OF GENERATOR INTERFACE VALUES ********//

#define MAXIMUM_GENSETS (uint8_t)6                      // Maximum number of Gensets that can be connected to the RS485 port of GX
#define MINIMUM_GENSETS (uint8_t)1                      // Minimum number of Gensets that can be connected to the RS485 port of GX
#define NO_GENSET (uint8_t)0                            // No Genset is connected connected to the RS485 port of GX
#define MAX_GENCONFIG_CHARS 65                          // The Max character size of the GenConfig for 1 Gen slot

/********* ERROR CODES FOR GEN CONFIGURATION ANOMALY EVENTS ********/

#define GENCONFIG_SLOT_ERROR -1        // Error returned when the 1st index (Gen slot) of the received Gen configuration is wrong.
#define GENCONFIG_NAME_ERROR -2        // Error returned when the 2nd index (Gen name) of the received Gen configuration is wrong.
#define GENCONFIG_TYPE_ERROR -3        // Error returned when the 3rd index (Gen type) of the received Gen configuration is wrong.
#define GENCONFIG_ADDRESS_ERROR -4     // Error returned when the 4th index (Gen address) of the received Gen configuration is wrong.
#define GENCONFIG_RELAY_ERROR -5       // Error returned when the 5th index (relay assigned) of the received Gen configuration is wrong.
#define GENCONFIG_KVA_ERROR -6         // Error returned when the 6th index (Gen kva) of the received Gen configuration is wrong.
#define GENCONFIG_BAUD_ERROR -7        // Error returned when the 7th index (Gen Baud) of the received Gen configuration is wrong.
#define GENCONFIG_SEQUENCE_ERROR -8    // Error returned if new config slot is not sequencial with the previous one; 1,2,..,6,1..,6

/********* ERROR CODES FOR DESCRIBING GEN CONTROL ANOMALY EVENTS ********/
#define UNCONFIGURED_GEN_UNIT_ERROR (int8_t)-9    // Gen unit does not exist e.g Trying to control Gen3 in a setup with 2 Gensets.
#define GEN_CTRL_CMD_ERROR (int8_t)-10            // 2nd index of cloud function argument is wrong e.g 1,stzrt or 2,statw or 3,srop
#define UNASSIGNED_CTRL_RLY_ERROR (int8_t)-11     // No relay was assigned to the Gen e.g Trying to stop a Gen with relay config = 0

//******** MODBUS POLLING RELATED VALUES ********//

#define MBDATA_BUFFER_SIZE (uint8_t)30                // Total size of array used as buffer for hold raw data retrieved from the RS485 port
#define EXT_MBDATA_BUFF_SIZE (uint8_t)25              // Size of Buffer used to temporarily collate Gen metrics before they are formatted
#define MBDATA_ALRM_BUFF_SIZE (uint8_t)24             // Size of Buffer used to temporarily collate Values read from Modbus Alarm Registers
#define PCC1302_ALRM_SIZE 60
#define MODBUS_ROLL_OVER_TIME 4*1000                  // 4 seconds time frame to wait for a response from the Modbus slave device

// Indicator that GX is the Modbus master on the RS485 Port. 1 means GX is the slave
#define GX_IS_MASTER 0 

// Indicates that RS485 communication is physically executing over the Serial1 module of the MCU  
#define MODBUS_ON_SERIAL1 1

// The number of places a single bit should be shifted to, during a Bit-Shift Operation.
#define MOVE_16_STEP 16

// Scaler required to derive a 32-Bits Number when reading Gen data from a Cummins GenSet
#define CUMMINS_32BIT_SCALER 65536

// Total number of supported alarms
#define TOTAL_SUPPORTED_ALARMS 24

// There is no active GenSet Alarm.
#define GEN_ALM_NONE 0                  

// The number of Modbus_Poll runs executed in a single Modbus read of the GenSet
#define MB_12_POLLS 12
#define MB_1_POLL 1   

//******** Query set Labels used for individual Genset Query Bank********//
#define GEN_QUERY1 (uint8_t)0
#define GEN_QUERY2 (uint8_t)1
#define GEN_QUERY3 (uint8_t)2
#define GEN_QUERY4 (uint8_t)3 

#define MAIN_GEN_METRIC_CHARS 10          // Maximum lenght of main gen metrics characters. 
#define GEN_ALRM_CHARS 100                // Maximum length of gen alarms values characters.

#define MB_SENTL_VAL -100000000.0f        // Indicator of a sentinel value that has been read from a Modbus device.
#define MB_UNAVAIL_VAL -101000000.0f      // Indicator of an unavailable Modbus metric.

#define MAIN_GEN_DATA_SIZE 52
#define BASIC_INST_GEN_DATA_SIZE 23
#define DERIV_INST_GEN_DATA_SIZE 14

#define ENGINE_AT_REST (uint8_t)0         // Indicator that the gen engine is at rest(not running)
#define ENGINE_RUNNING (uint8_t)3         // Indicator that the gen engine is not at rest (running) 
#define ENGINE_STATE_UNKNOWN (uint8_t)5   // Indicator that the gen engine could not be determined (Due to a Modbus read error)  

constexpr uint8_t NUM_OF_ENGSTATE_REGS = 1;   // Number of registers that hold the Engine state metric in a Genset
constexpr uint8_t ENGSTATE_BUFF_INDX = 0;     // Array index of the modbus data buffer holding the engine status data
constexpr float MULTPLR_PT1 = 0.1f;           // Number Multiplier : Used to achieve arithmetic division by 10.
constexpr float MULTPLR_PT01 = 0.01f;         // Number Multiplier : Used to achieve arithmetic division by 100.

// Data structure of the Gen Controller's Query bank
struct GeneratorQueryKey 
{
    uint16_t start_addr;
    uint16_t num_of_regs;
};

// List of Generator controller types supported by the GX device 
enum GeneratorType {
    NO_TYPE,
    DCP_10,
    DSE_857,
    PCC_1302,
    APM_303 
};

// List of Generators to be connected with the GX device
enum GeneratorSlot {
    NO_GEN_SPECIFIED,
    GEN1,
    GEN2,
    GEN3,
    GEN4,
    GEN5,
    GEN6,
    GENS_REMOVED
    
};

// List of Eligible Baud rates for Modbus communication
enum GeneratorBaudRate {
    BAUD_9K6,
    BAUD_14K4,
    BAUD_19K2,
    BAUD_38K4,
    BAUD_57K6,
    BAUD_115K2,
    BAUD_128K
};
    
// The relevent data polled from the Gen controller are grouped into 3 data sets
enum GeneratorDataSet
{
    GEN_MAIN,
    GEN_BASINST,
    GEN_DERINST,
    GEN_ENG_STATUS,
    GEN_READY,
    GEN_NOT_READY
};

// List of Generator metrics within the Main data group
enum MainGenDataGroup
{
    RUN_HRS, 
    NUM_OF_STARTS, 
    CTRL_MODE, 
    ENGINE_STATE,
    ALARM_CODE1
};

//List of Generator metrics within the Basic Instrumentation data group
enum BasInstGenDataGroup
{
    TOTAL_KWH, 
    OIL_PRESSR, 
    COOL_TEMP, 
    OIL_TEMP, 
    FUEL_LEVEL, 
    CHARGER_ALT_VOLT, 
    ENGINE_BATT_VOLT, 
    ENGINE_SPEED, 
    GEN_FREQCY,
    L1_N_VOLT, 
    L2_N_VOLT, 
    L3_N_VOLT, 
    L1_L2_VOLT, 
    L2_L3_VOLT, 
    L3_L1_VOLT, 
    L1_CURR, 
    L2_CURR, 
    L3_CURR, 
    EARTH_CURR, 
    L1_WATT,
    L2_WATT, 
    L3_WATT, 
    CURR_LAG_LEAD
};

// List of Generator metrics within the Derived Instrumentation data group
enum DerInstGenDataGroup
{
    TOTAL_WATT, 
    L1_KVA, 
    L2_KVA, 
    L3_KVA, 
    TOTAL_KVA, 
    L1_KVAR, 
    L2_KVAR, 
    L3_KVAR, 
    TOTAL_KVAR, 
    L1_PF, 
    L2_PF, 
    L3_PF, 
    AVER_PF,
    PERCENT_OF_FULL_POWER
};

// List of Modbus register from which Generator alarms are derived
enum GenAlarmRegister
{
    ALARM_REG1, 
    ALARM_REG2, 
    ALARM_REG3, 
    ALARM_REG4, 
    ALARM_REG5, 
    ALARM_REG6,
    ALARM_REG7,
    ALARM_REG8,
    ALARM_REG9,
    ALARM_REG10,
    ALARM_REG11,
    ALARM_REG12,
    ALARM_REG13,
    ALARM_REG14,
    ALARM_REG15,
    ALARM_REG16,
    ALARM_REG17,
    ALARM_REG18,
    ALARM_REG19,
    ALARM_REG20,
    ALARM_REG21,
    ALARM_REG22,
    ALARM_REG23,
    ALARM_REG24
};

// List of possible Genset Control Mode 
enum GensetControlMode
{
    GEN_STOP_MODE,
    GEN_AUTO_MODE,
    GEN_MANUAL_MODE
};

// The available onboard relays on GX for Genset START/STOP
enum GXGenControlRelay
{
    UNAVAIL_GX_RELAY,
    GX_RELAY_1,
    GX_RELAY_2
};

// States of GX Onbaord Relays. The relays can only exist in these 4 states.
enum GXOnboardRelayStates
{
    RELAY_1_2_OFF,      // RELAY_1 = OFF, RELAY_2 = OFF.
    RELAY_1_ON,         // RELAY_1 = ON, RELAY_2 = OFF.
    RELAY_2_ON,         // RELAY_1 = OFF, RELAY_2 = ON.
    RELAY_1_2_ON        // RELAY_1 = ON, RELAY_2 = ON.
};

// Genset control command received from particle cloud
enum GenControlCommand 
{
    SHUTDOWN_GEN,
    RUN_GEN,
    GET_GEN_STATE
};




/********** NOTE: These would be moved to a seperate header file subsequetly. Leaving them here for now **********
 *
 *                                    SUPPORTED GRID METRICS DEFINITIONS
*/

#define BASINST_GRID_DATA_SIZE 16       // Total number of available Basic Instrumentation Grid-Data
#define DERINST_GRID_DATA_SIZE 14       // Total number of available Derived Instrumentation Grid-Data

//List of the State of Grid Metrics. It shows where the metrics are read from. 
enum GridMetricsSource
{
    GRID_MTRCS_OFF,        // Grid metrics are deactivated on the device
    GRID_MTRCS_GEN,        // Grid metrics are collected from a Genset controller
    GRID_MTRCS_METER       // Grid metrics are collected from a Smart meter module
};

// Grid metrics read from a source device (Genset or Smart meter) are classified into these groups.
enum GridDataSet 
{
    GRID_DONE,             // The data was read correctly
    GRID_BAS_INST,         // Basic instrumentation Grid metrics
    GRID_DER_INST,         // Derived instrumentation Grid metrics
    GRID_UNDONE            // The data was not read correctly
};

// List of Basic instrumentation GRID metrics supported by GX
enum BasicInstGridMetrics
{
    GRID_ACCUM_KWH,
    GRID_FREQ,
    GRID_L1_N_VOLT,
    GRID_L2_N_VOLT,
    GRID_L3_N_VOLT,
    GRID_L1_L2_VOLT,
    GRID_L2_L3_VOLT,
    GRID_L3_L1_VOLT,
    GRID_AMP_LAG_LEAD,
    GRID_L1_AMP,
    GRID_L2_AMP,
    GRID_L3_AMP,
    GRID_EARTH_AMP,
    GRID_L1_WATT,
    GRID_L2_WATT,
    GRID_L3_WATT
};

// List of Derived instrumentation GRID metrics supported by GX
enum DerivedInstGridMetrics
{
    TOTAL_GRID_KW,
    GRID_L1_VA,
    GRID_L2_VA,
    GRID_L3_VA,
    GRID_TOTAL_VA,
    GRID_L1_VAR,
    GRID_L2_VAR,
    GRID_L3_VAR,
    GRID_TOTAL_VAR,
    GRID_L1_PF,
    GRID_L2_PF,
    GRID_L3_PF,
    GRID_AVERAGE_PF,
    PERCENT_OF_GRID_POWER
};


// Data structure that encapsulutes the configuration of any Genset connected to the GX device
struct GeneratorConfig {

    char name[MAX_GEN_NAME_LENGTH + ZERO_INDEX_CORRECTION] = NULL_STRING;    // Name given to the Genset by the owner
    uint8_t type = UINT8_MAX;                                                // Identity of the Genset controller 
    uint8_t slave_id = UINT8_MAX;                                            // Modbus slave ID of Genset controller
    uint8_t relay = UINT8_MAX;                                               // Onboard relay assigned to the Genset. 0:none, 1:RLY1, 2:RLY2
    uint16_t kva_rating = UINT16_MAX;                                        // KVA rating of the Genset
    uint8_t baud_rate = UINT8_MAX;                                           // Communication baudrate of the Genset controller 
};
#endif // SHYFTDEFINES_SRC_GENERATORDEFINITIONS_H_
