#ifndef MONITORENGINE_HPP
#define MONITORENGINE_HPP

#include "ISensor.hpp"

#include <memory>
#include <vector>
#include <thread>
#include <atomic>

/**
 * @brief Central engine that manages and polls sensors.
 *
 * Runs a background thread to continuously retrieve sensor data.
 */
class MonitorEngine {
public:
    MonitorEngine();
    ~MonitorEngine();

    // Prevent copying (owning threads/resources)
    MonitorEngine(const MonitorEngine&) = delete;
    MonitorEngine& operator=(const MonitorEngine&) = delete;

    /**
     * @brief Adds a sensor to the monitoring engine.
     */
    void addSensor(std::unique_ptr<ISensor> sensor);

    /**
     * @brief Starts background monitoring.
     */
    void start();

    /**
     * @brief Stops background monitoring.
     */
    void stop();

private:
    void monitoringLoop();

    std::vector<std::unique_ptr<ISensor>> sensors_;
    std::thread workerThread_;
    std::atomic<bool> running_;
};

#endif // MONITORENGINE_HPP
