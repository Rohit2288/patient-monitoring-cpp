# Modular Medical-Grade Patient Monitoring Subsystem (C++)

##  Overview
This project implements a modular, production-style C++ subsystem that simulates a medical bedside patient monitoring system. The focus is on safety, reliability, fault handling, and maintainability, similar to real-world medical device software.

The system continuously monitors patient vitals (heart rate and body temperature), evaluates them against clinical safety thresholds, raises alarms for unsafe conditions, and logs events to support investigation and maintenance.

---

##  System Architecture

The system follows a **Producer-Consumer** pattern driven by a background polling thread.

1.  **Sensor Polling:** The `MonitorEngine` manages a collection of `ISensor` implementations.
2.  **Data Processing:** A background thread polls sensors at regular intervals.
3.  **Safety Evaluation:** Raw data is passed to the `AlarmManager` to check against clinical thresholds.
4.  **Logging:** All safety events and sensor failures are routed through the thread-safe `SystemLogger`.

### Data Flow
* **Input:** Hardware Simulation (`HeartRateSensor`, `TemperatureSensor`)
* **Processing:** `MonitorEngine` (Polling Loop + Thread Safety)
* **Decision:** `AlarmManager` (Tachycardia/Fever Logic)
* **Output:** `SystemLogger` (Persistent Audit Trail)

---

##  Components

### ISensor (Interface)
Defines a common contract for all sensors:
* `getReading()`: Returns `std::optional<double>` to safely represent sensor failures without using magic numbers.
* `performSelfTest()`: Simulates sensor self-diagnostics.

### Sensor Implementations
* **HeartRateSensor:** Simulates heart rate readings (BPM).
* **TemperatureSensor:** Simulates body temperature readings (°C).

### MonitorEngine
* Owns all sensors using `std::unique_ptr`.
* Runs a background thread to poll sensors periodically.
* Integrates alarm evaluation and logging.
* Ensures clean startup and shutdown using **RAII**.

### AlarmManager
* Centralized patient safety logic.
* Evaluates readings against predefined safety thresholds.
* Generates alarm messages for unsafe conditions (e.g., tachycardia, fever).

### SystemLogger
* Thread-safe logging using `std::mutex`.
* Logs alarms and sensor failures with timestamps.
* Supports investigation, maintenance, and complaint handling.

---

##  Testing
Safety-critical logic is verified using **GoogleTest**:
* **Heart rate alarm triggering:** Boundary testing for BPM limits.
* **Temperature alarm triggering:** Validation of fever thresholds.
* **Safe boundary conditions:** Ensuring no false positives.

Tests are deterministic and independent of threading logic to ensure reliability.

---

##  Build & Run Instructions

### Build
```bash
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make

---


Run the System
./patient_monitor

Run Unit Tests
ctest

---

Technologies Used
C++17

CMake

GoogleTest

Multithreading: std::thread

Memory Management: RAII and Smart Pointers (std::unique_ptr)

STL: std::optional, std::vector, std::atomic

Note: This project focuses on core monitoring and safety logic rather than user interface development. In real medical systems, this subsystem would be consumed by a system-level UI or device firmware.