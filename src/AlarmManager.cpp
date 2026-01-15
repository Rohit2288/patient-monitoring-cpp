#include "AlarmManager.hpp"

AlarmManager::AlarmManager()
    : maxHeartRate_(100.0),
      maxTemperature_(38.0) {
}

std::optional<std::string>
AlarmManager::evaluateHeartRate(double bpm) const {
    if (bpm > maxHeartRate_) {
        return "ALARM: Heart rate exceeds safe limit (Tachycardia)";
    }
    return std::nullopt;
}

std::optional<std::string>
AlarmManager::evaluateTemperature(double temperature) const {
    if (temperature > maxTemperature_) {
        return "ALARM: Temperature exceeds safe limit (Fever)";
    }
    return std::nullopt;
}
