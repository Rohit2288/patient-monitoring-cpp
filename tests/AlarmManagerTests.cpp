#include <gtest/gtest.h>
#include "AlarmManager.hpp"

/**
 * @brief Tests for AlarmManager safety logic.
 */

TEST(AlarmManagerTest, HeartRateWithinSafeLimit_NoAlarm) {
    AlarmManager alarmManager;
    auto alarm = alarmManager.evaluateHeartRate(80.0);
    EXPECT_FALSE(alarm.has_value());
}

TEST(AlarmManagerTest, HeartRateAboveLimit_TriggersAlarm) {
    AlarmManager alarmManager;
    auto alarm = alarmManager.evaluateHeartRate(120.0);
    ASSERT_TRUE(alarm.has_value());
}

TEST(AlarmManagerTest, TemperatureWithinSafeLimit_NoAlarm) {
    AlarmManager alarmManager;
    auto alarm = alarmManager.evaluateTemperature(36.8);
    EXPECT_FALSE(alarm.has_value());
}

TEST(AlarmManagerTest, TemperatureAboveLimit_TriggersAlarm) {
    AlarmManager alarmManager;
    auto alarm = alarmManager.evaluateTemperature(39.0);
    ASSERT_TRUE(alarm.has_value());
}
