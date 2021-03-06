/*
author : ayaz
copyright: aplombtechbd

this file is the Test Runner
TDD is followed as top down approach 
*/

//#define UNIT_TESTING

#ifdef UNIT_TESTING

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>  // Brings in Google Mock.
#include <arduino-mock/Arduino.h>

#include "../arduino-mock-sample.ino"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST(digitalRead, 2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalRead(2)).WillOnce(Return(1));
  digitalRead(2);
  releaseArduinoMock();
}

TEST(delay, normal) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, delay(1));
  delay(1);
  releaseArduinoMock();
}

TEST(sketch,setup) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, pinMode(13, OUTPUT));
  setup();
  releaseArduinoMock();
}

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif