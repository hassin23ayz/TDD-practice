// sq-root.cpp

#include <iostream>

#include <gtest/gtest.h>
#include "gmock/gmock.h"  // Brings in Google Mock.

#include "LedDriver.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class LedDriverTest : public ::testing::Test
{
protected:
     uint16_t ledStatus = 0xFFFF;  //faking data 
     virtual void SetUp()
     {      
         ledDriver_create(&ledStatus);
     }
     virtual void TearDown()
     {}
};

TEST(LedDriver, LedsOffAfterCreate){
  //arrange
  uint16_t ledStatus = 0xFFFF;  //faking data 
  //act
  ledDriver_create(&ledStatus); //will create and read led status data 
  //assert
  EXPECT_EQ(0, ledStatus);      //after create all Leds should be 0 
  //EXPECT_TRUE(false) << "start here";
}

TEST_F(LedDriverTest, TurnOnLedOne){
  //arrange
  //act
  ledDriver_turnOn(1);
  //assert
  EXPECT_EQ(1, ledStatus);      
}

TEST_F(LedDriverTest, TurnOffLedOne){
  //setup
  //exercise
  ledDriver_turnOn(1);
  ledDriver_turnOff(1);
  //verify
  EXPECT_EQ(0, ledStatus);
  //cleanup
}

TEST_F(LedDriverTest, TurnOnMultipleLeds){
  //setup
  //exercise
  ledDriver_turnOn(9);
  ledDriver_turnOn(8);
  //verify
  EXPECT_EQ(0x180, ledStatus);
  //cleanup
}

TEST_F(LedDriverTest, TurnOffAnyLed){
  //setup
  //exercise
  ledDriver_turnAllOn();
  ledDriver_turnOff(8);
  //verify
  EXPECT_EQ(0xFF7F, ledStatus);
  //cleanup
}

TEST_F(LedDriverTest, AllOn){
  //setup
  //exercise
  ledDriver_turnAllOn();
  //verify
  EXPECT_EQ(0xFFFF, ledStatus);
  //cleanup
}

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}