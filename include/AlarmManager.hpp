#ifndef ALARMMANAGER_HPP
#define ALARMMANAGER_HPP

#include <string>
#include <optional>

/**
 * @brief Evaluates sensor readings against safety thresholds.
 *
 * This class encapsulates all patient safety logic.
 */
class AlarmManager {
public:
    AlarmManager();

    /**
     * @brief Evaluates a heart rate reading.
     *
     * @return Optional alarm message if unsafe.
     */
    std::optional<std::string> evaluateHeartRate(double bpm) const;

    /**
     * @brief Evaluates a temperature reading.
     *
     * @return Optional alarm message if unsafe.
     */
    std::optional<std::string> evaluateTemperature(double temperature) const;

private:
    double maxHeartRate_;
    double maxTemperature_;
};

#endif // ALARMMANAGER_HPP
