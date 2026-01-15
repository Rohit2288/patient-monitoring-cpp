#ifndef HEARTRATESENSOR_HPP
#define HEARTRATESENSOR_HPP

#include "ISensor.hpp"

/**
 * @brief Concrete implementation of a heart rate sensor.
 *
 * Simulates heart rate readings in beats per minute (BPM).
 */
class HeartRateSensor : public ISensor {
public:
    HeartRateSensor();

    std::string getName() const override;
    std::optional<double> getReading() override;
    bool performSelfTest() const override;
};

#endif // HEARTRATESENSOR_HPP
