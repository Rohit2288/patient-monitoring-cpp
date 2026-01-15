#ifndef TEMPERATURESENSOR_HPP
#define TEMPERATURESENSOR_HPP

#include "Isensor.hpp"

/**
 * @brief Concrete implementation of a temperature sensor.
 *
 * Simulates body temperature readings in degrees Celsius.
 */
class TemperatureSensor : public ISensor {
public:
    TemperatureSensor();

    std::string getName() const override;
    std::optional<double> getReading() override;
    bool performSelfTest() const override;
};

#endif // TEMPERATURESENSOR_HPP
