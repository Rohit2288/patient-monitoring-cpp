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
    src/SystemLogger.cpp
)

# -----------------------
# Unit Tests
# -----------------------

enable_testing()

find_package(GTest REQUIRED)

add_executable(alarm_manager_tests
    tests/AlarmManagerTests.cpp
    src/AlarmManager.cpp
)

target_include_directories(alarm_manager_tests PRIVATE include)

target_link_libraries(alarm_manager_tests GTest::gtest GTest::gtest_main)

add_test(NAME AlarmManagerTests COMMAND alarm_manager_tests)
