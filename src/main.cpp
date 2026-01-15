#include "MonitorEngine.hpp"
#include "HeartRateSensor.hpp"
#include "TemperatureSensor.hpp"

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Starting Patient Monitoring System..." << std::endl;

    MonitorEngine engine;

    // Add sensors to the engine
    engine.addSensor(std::make_unique<HeartRateSensor>());
    engine.addSensor(std::make_unique<TemperatureSensor>());

    // Start monitoring
    engine.start();

    // Let the system run for 10 seconds
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // Stop monitoring
    engine.stop();

    std::cout << "Monitoring stopped. Exiting system." << std::endl;

    return 0;
}
