#ifndef RESET_REASONS
#define RESET_REASONS

#include "Particle.h"

// Particle-defined reset reasons are in this file:
// https://github.com/particle-iot/firmware/blob/f173a0dcaba29061d06a967147c81a5707eb9790/hal/inc/core_hal.h#L61
// This is the same for firmware version 0.6.4 through 0.8.0-rc.8
namespace Reset
{
  enum Reason : unsigned int {
    // App-specific
    CLOUD_RESET_HARD = 138, // reset because it was requested by cloud
    CLOUD_RESET = 148, // reset because it was requested by cloud
    HIGH_MEMORY = 158, // reset because memory over 80% (or whatever threshold)
    MILLIS_THRESHOLD = 168, // reset because device alive for > MILLIS_RESET_THRESHOLD
    MANUAL_MODE = 178, // reset because we came out of manual mode
    CUSTOM_WATCHDOG = 188, // watchdog because unsure if it actually stores it when we call custom watchdog.
    POWER_SAVE_MODE = 198, //reset because we were previously in power save mode, now coming out of it

    // This is to signify if we don't have an "App-Specific" reason.
    APP_NONE = 8,

    // --- Mapping Particle-defined reset reasons --- //
    PARTICLE_NONE = RESET_REASON_NONE, // 0
    UNKNOWN = RESET_REASON_UNKNOWN, // 10
    // Hardware
    PIN_RESET = RESET_REASON_PIN_RESET, // 20
    POWER_MANAGEMENT = RESET_REASON_POWER_MANAGEMENT, // 30
    POWER_DOWN = RESET_REASON_POWER_DOWN, // 40
    POWER_BROWNOUT = RESET_REASON_POWER_BROWNOUT, // 50
    WATCHDOG = RESET_REASON_WATCHDOG, // 60
    // Software
    UPDATE = RESET_REASON_UPDATE, // 70
    UPDATE_ERROR = RESET_REASON_UPDATE_ERROR, // 80
    UPDATE_TIMEOUT = RESET_REASON_UPDATE_TIMEOUT, // 90
    FACTORY_RESET = RESET_REASON_FACTORY_RESET, // 100
    SAFE_MODE = RESET_REASON_SAFE_MODE, // 110
    DFU_MODE = RESET_REASON_DFU_MODE, // 120
    PANIC = RESET_REASON_PANIC, // 130
    USER = RESET_REASON_USER, // 140
  };
};

#endif
