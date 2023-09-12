#ifndef SOURCE_CHANGE_DEFINITIONS
#define SOURCE_CHANGE_DEFINITIONS

#include "Particle.h"
#include "EnumDefinitions.h"

namespace SourceChange {
  enum SwitchState : uint8_t {
    SWITCH_STATE_NONE = 0,
    SWITCH_STATE_REQUESTED = 1,
    SWITCH_STATE_WAITING_FOR_SOURCE = 2,
    SWITCH_STATE_SOURCE_READY = 3,
    SWITCH_STATE_SWITCH_MADE = 4,
    SWITCH_STATE_CONFIRMING = 5,
    SWITCH_STATE_FAILED = 6,
    SWITCH_STATE_WAITING_FOR_RETRY = 7,
    SWITCH_STATE_RETURNING_TO_PREV = 8,
    SWITCH_STATE_SUCCEEDED = 9,
  };

  enum FailureReason : uint8_t {
    FAILURE_REASON_NONE = 0, // this means it didn't fail.
    FAILURE_REASON_UNAVAIL = 1, // source no longer available
    FAILURE_REASON_LOW_VOLTAGE = 2, // low voltage (not yet used, but could be based on our voltage sampling)
    FAILURE_REASON_CONFIRM_FAILED = 3,
    FAILURE_REASON_SOURCE_FAILED = 4, // this is for gen case; if gen fails to start we use this
    FAILURE_REASON_CANCELED = 5, // this is if another source change cancels the existing one
    FAILURE_REASON_UNKNOWN = 6,
  };

  struct State {
    SwitchState switchState;
    // GenState genState;
    PowerSource previousSource;
    PowerSource currentSource;
    PowerSource desiredSource;
    bool isRetry;
    bool attempted;
    SourceChange::FailureReason failureReason;
  };

  const State DefaultState = {
    SourceChange::SWITCH_STATE_NONE, // switchState
    PowerSource::NONE, // previousSource
    PowerSource::OFF, // currentSource -- should this be "off", or none?
    PowerSource::NONE, // desiredSource
    false, // isRetry
    false, // attempted
    SourceChange::FAILURE_REASON_NONE  // failureReason
  };
};

bool operator==(const SourceChange::State& lhs, const SourceChange::State& rhs);
bool operator!=(const SourceChange::State& lhs, const SourceChange::State& rhs);

#endif
