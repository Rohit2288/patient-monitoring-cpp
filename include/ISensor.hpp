#ifndef ISENSOR_HPP
#define ISENSOR_HPP

#include <optional>
#include <string>

/**
 * @brief Abstract interface representing a medical sensor.
 *
 * This interface defines the minimum contract that all sensors
 * (heart rate, temperature, etc.) must follow.
 * It enables safe data acquisition and fault handling.
 */
class ISensor {
public:
    // Virtual destructor ensures proper cleanup via base pointer
    virtual ~ISensor() = default;

    /**
     * @brief Returns the name of the sensor.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Retrieves the latest sensor reading.
     *
     * @return std::optional<double>
     *         - contains a value if reading is valid
     *         - std::nullopt if sensor failed or data unavailable
     */
    virtual std::optional<double> getReading() = 0;

    /**
     * @brief Performs a self-test to verify sensor health.
     *
     * @return true if sensor is functioning correctly
     */
    virtual bool performSelfTest() const = 0;
};

#endif // ISENSOR_HPP
