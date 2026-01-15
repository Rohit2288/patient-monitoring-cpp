#ifndef SYSTEMLOGGER_HPP
#define SYSTEMLOGGER_HPP

#include <string>
#include <mutex>

/**
 * @brief Thread-safe system logger for maintenance and investigation.
 *
 * Records alarms and system events with timestamps.
 */
class SystemLogger {
public:
    /**
     * @brief Logs an informational message.
     */
    void logInfo(const std::string& message);

    /**
     * @brief Logs a warning or alarm message.
     */
    void logWarning(const std::string& message);

private:
    void log(const std::string& level, const std::string& message);

    std::mutex logMutex_;
};

#endif // SYSTEMLOGGER_HPP
