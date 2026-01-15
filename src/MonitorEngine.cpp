#include "MonitorEngine.hpp"

#include <iostream>
#include <chrono>

/**
 * @brief Constructor initializes engine state.
 */
MonitorEngine::MonitorEngine()
    : running_(false) {
}

/**
 * @brief Destructor ensures monitoring is stopped.
 */
MonitorEngine::~MonitorEngine() {
    stop();
}

/**
 * @brief Adds a sensor to the engine.
 */
void MonitorEngine::addSensor(std::unique_ptr<ISensor> sensor) {
    sensors_.push_back(std::move(sensor));
}

/**
 * @brief Starts the monitoring thread.
 */
void MonitorEngine::start() {
    if (running_) {
        return;
    }

    running_ = true;
    workerThread_ = std::thread(&MonitorEngine::monitoringLoop, this);
}

/**
 * @brief Stops the monitoring thread.
 */
void MonitorEngine::stop() {
    if (!running_) {
        return;
    }

    running_ = false;

    if (workerThread_.joinable()) {
        workerThread_.join();
    }
}

/**
 * @brief Background loop that polls sensors.
 */
void MonitorEngine::monitoringLoop() {
    while (running_) {
        for (const auto& sensor : sensors_) {
            auto reading = sensor->getReading();

            if (reading.has_value()) {
    std::cout << sensor->getName()
              << " reading: "
              << reading.value()
              << std::endl;

    // Evaluate safety
    if (sensor->getName() == "Heart Rate Sensor") {
        auto alarm = alarmManager_.evaluateHeartRate(reading.value());
        if (alarm.has_value()) {
            std::cout << alarm.value() << std::endl;
        }
    }

    if (sensor->getName() == "Temperature Sensor") {
        auto alarm = alarmManager_.evaluateTemperature(reading.value());
        if (alarm.has_value()) {
            std::cout << alarm.value() << std::endl;
        }
    }
}
else {
                std::cout << sensor->getName()
                          << " reading unavailable"
                          << std::endl;
            }
        }

        std::cout << "--------------------------" << std::endl;

        // Poll every 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
