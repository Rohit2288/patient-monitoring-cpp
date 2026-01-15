cmake_minimum_required(VERSION 3.10)

project(patient_monitoring_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(patient_monitor
    src/main.cpp
    src/MonitorEngine.cpp
    src/HeartRateSensor.cpp
    src/TemperatureSensor.cpp
    src/AlarmManager.cpp
)
