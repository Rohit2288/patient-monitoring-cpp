#include "TemperatureSensor.hpp"

#include <cstdlib>
#include <ctime>

/**
 * @brief Constructor initializes random seed.
 */
TemperatureSensor::TemperatureSensor() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

std::string TemperatureSensor::getName() const {
    return "Temperature Sensor";
}

std::optional<double> TemperatureSensor::getReading() {
    // Simulate sensor failure (10% chance)
    if (std::rand() % 10 == 0) {
        return std::nullopt;
    }

    // Simulate temperature between 36.0 and 39.0 °C
    double temperature = 36.0 + (std::rand() % 31) / 10.0;
    return temperature;
}

bool TemperatureSensor::performSelfTest() const {
    // Simulate that sensor usually passes self-test
    return true;
}
