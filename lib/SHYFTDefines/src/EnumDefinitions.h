#ifndef SHYFTDEFINES_SRC_ENUMDEFINITIONS_H_
#define SHYFTDEFINES_SRC_ENUMDEFINITIONS_H_

#include "ResetReasons.h"

typedef int16_t ErrCode;

enum ret_error_code
{
  PORT_EXPANDER,
  SPIFLASH,
  THERMCPL,
  INIT_SUCCESS
};

enum MikrobusConfig : uint8_t {
  MIKROBUS_CONFIG_NONE = 0,
  MIKROBUS_CONFIG_EXT_REMOTE_START_HIGH = 1,
  MIKROBUS_CONFIG_EXT_REMOTE_START_LOW = 2,
};

enum PowerSource : uint8_t {
  OFF = 0,
  GRID = 1,
  GEN = 2,
  UNKNOWN = 10,
  NONE = 10
};

enum TimerType {
  TIMER_NONE = 0,
  TIMER_GRID_STABILIZATION = 1, //TDEN
  TIMER_GRID_FAILED_AUTO_MODE = 2, // TDES
  TIMER_GEN_STARTING = 3,
  TIMER_GEN_WARMUP = 4, // TDNE,
  TIMER_GEN_STOPPING = 5,
  TIMER_NO_SYNC = 10,
};

/**
 * @brief DeepSea Alarm state enums
 * 
 */
enum AlarmState
{
  // We probably won't send these but let's keep them here anyway
  NOT_FITTED = 0,
  INACTIVE = 1,
  WARNING = 2,
  SHUTDOWN = 3,
  ELECTRICAL_TRIP = 4,
  CONTROLLED_SHUTDOWN_ALARM = 5,
  // 6 through 9 are values that will be ignored (not sent from GX)
  ACTIVE_INDICATION = 10,
  // 11 through 15 are values that will be ignored (not sent from GX)
};

/**
 * @brief LED modes for indication routines
 * 
 */
enum LEDmodes
{
  LED_OFF = 0,
  LED_SOLID,
  LED_BLINK,
  LED_BLINK_ERROR
};

enum class bool_State
{
  RAN_ONCE = true,
  RAN_MORE = false
};

#endif // SHYFTDEFINES_SRC_ENUMDEFINITIONS_H_
