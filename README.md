# Modular Medical-Grade Patient Monitoring Subsystem (C++)

## Overview
This project implements a modular, production-style C++ subsystem that simulates a **medical bedside patient monitoring system**.  
The focus is on **safety, reliability, fault handling, and maintainability**, similar to real-world medical device software.

The system continuously monitors patient vitals (heart rate and body temperature), evaluates them against clinical safety thresholds, raises alarms for unsafe conditions, and logs events to support investigation and maintenance.

This project is designed as a **core subsystem** (not a UI application) and is intended to be integrated into a higher-level medical device or monitoring application.

---

## Key Design Objectives
- Modular architecture using abstract interfaces
- Safe handling of sensor failures using `std::optional`
- Clear separation of concerns (monitoring, safety logic, logging)
- Thread-safe operation
- Verification of safety logic through unit testing

---

## System Architecture

+------------------+

MonitorEngine
- Owns sensors
- Background
polling thread
+--------+---------+
     |
     v
+------------------+ +------------------+
| AlarmManager | -----> | SystemLogger |
|------------------| |------------------|
| - Safety rules | | - Thread-safe |
| - Thresholds | | - Investigation |
+------------------+ +------------------+

---

## Components

### ISensor (Interface)
Defines a common contract for all sensors:
- `getReading()` returns `std::optional<double>` to safely represent sensor failures
- `performSelfTest()` simulates sensor self-diagnostics

### Sensor Implementations
- **HeartRateSensor** – Simulates heart rate readings (BPM)
- **TemperatureSensor** – Simulates body temperature readings (°C)

### MonitorEngine
- Owns all sensors using `std::unique_ptr`
- Runs a background thread to poll sensors periodically
- Integrates alarm evaluation and logging
- Ensures clean startup and shutdown using RAII

### AlarmManager
- Centralized patient safety logic
- Evaluates readings against predefined safety thresholds
- Generates alarm messages for unsafe conditions (e.g., tachycardia, fever)

### SystemLogger
- Thread-safe logging using `std::mutex`
- Logs alarms and sensor failures with timestamps
- Supports issue investigation, maintenance, and complaint handling

---

## Testing
Safety-critical logic is verified using **GoogleTest**:
- Heart rate alarm triggering
- Temperature alarm triggering
- Safe boundary conditions

Tests are deterministic and independent of threading logic.

---

## Build & Run Instructions

### Build
```bash
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make

Run the System
./patient_monitor

Run Unit Tests
ctest

Technologies Used

C++17

CMake

GoogleTest

Multithreading (std::thread)

RAII and Smart Pointers (std::unique_ptr)

STL (std::optional, std::vector, std::atomic)

Notes

This project focuses on core monitoring and safety logic rather than user interface development.
In real medical systems, this subsystem would be consumed by a higher-level UI or device firmware.