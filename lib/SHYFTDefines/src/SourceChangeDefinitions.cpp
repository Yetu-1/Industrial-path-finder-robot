#include "SourceChangeDefinitions.h"

bool operator==(const SourceChange::State& lhs, const SourceChange::State& rhs) {
  return (rhs.switchState == lhs.switchState &&
      rhs.previousSource == lhs.previousSource &&
      rhs.currentSource == lhs.currentSource &&
      rhs.desiredSource == lhs.desiredSource &&
      rhs.isRetry == lhs.isRetry &&
      rhs.attempted == lhs.attempted &&
      rhs.failureReason == lhs.failureReason);
}

bool operator!=(const SourceChange::State& lhs, const SourceChange::State& rhs) {
  return !(lhs == rhs);
}
