#include "HeartRateSensor.hpp"

#include <cstdlib>
#include <ctime>

/**
 * @brief Constructor initializes random seed.
 */
HeartRateSensor::HeartRateSensor() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

std::string HeartRateSensor::getName() const {
    return "Heart Rate Sensor";
}

std::optional<double> HeartRateSensor::getReading() {
    // Simulate sensor failure (10% chance)
    if (std::rand() % 10 == 0) {
        return std::nullopt;
    }

    // Simulate heart rate between 60 and 100 BPM
    int bpm = 60 + (std::rand() % 41);
    return static_cast<double>(bpm);
}

bool HeartRateSensor::performSelfTest() const {
    // Simulate that sensor usually passes self-test
    return true;
}
