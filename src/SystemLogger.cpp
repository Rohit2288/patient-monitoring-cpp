#include "SystemLogger.hpp"

#include <iostream>
#include <chrono>
#include <ctime>

void SystemLogger::logInfo(const std::string& message) {
    log("INFO", message);
}

void SystemLogger::logWarning(const std::string& message) {
    log("WARNING", message);
}

void SystemLogger::log(const std::string& level, const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex_);

    auto now = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());

    std::cout << "[" << level << "] "
              << std::ctime(&now)
              << "  " << message
              << std::endl;
}
