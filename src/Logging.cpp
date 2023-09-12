#include "Logging.h"

LogLevel DEFAULT_LOG_LEVEL = (SHYFT_DEBUG) ? LOG_LEVEL_TRACE : LOG_LEVEL_WARN;

// NOTE: default Logger name is "app" so we don't need to
// explicitly declare that one in main.cpp, but for the others,
// with non-default names, we will
SerialLogHandler logHandler(LOG_LEVEL_INFO, { // Logging level for non-application messages
    { "app", DEFAULT_LOG_LEVEL }, // Default logging level for all application messages
    { ROBOT_STATE_LOGGER_NAME, LOG_LEVEL_INFO  }, // Logging level for SHYFTStateSync
    { "app.spiffs", LOG_LEVEL_WARN } // To disable spiffs internal info and trace messages, set to WARN
});
