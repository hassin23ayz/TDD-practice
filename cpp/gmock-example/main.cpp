// sq-root.cpp

#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>  // Brings in Google Mock.

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class EEPROM{
public:
  virtual bool clear(void) {
    cout << "original EEPROM clear() called" <<endl;
    return true;
  }
  virtual bool write(uint16_t address, uint8_t value) {
    cout << "original EEPROM write() called" <<endl;
    return true;
  }
  virtual uint8_t read(uint16_t address) {return 123;}
};

class EEPROMMock : public EEPROM {
 public:
  MOCK_METHOD0(clear, bool ());
  MOCK_METHOD1(read, uint8_t (uint16_t address));
  MOCK_METHOD2(write, bool (uint16_t address, uint8_t value));
};

class MyDataBase{
  EEPROM& eepm;
public:
  MyDataBase(EEPROM& _eepm): eepm(_eepm) {}
  
  int initDataBase(void){
    if(eepm.clear() != true){
      cout << "Database init failure" <<endl;
      return -1;
    }
    else{
      cout << "Database init success" <<endl;
      return 1;
    }
  }

  int writeDataBase(uint8_t val){
    if(eepm.write(444, val) != true){
      cout << "Database write Failure" <<endl;
      return -1;
    }
    else{
      cout << "Database write success" <<endl;
      return 1;
    }
  }
};

TEST(MyDBTest, initTest){
  //arrange
  EEPROMMock eepM;
  MyDataBase myDB(eepM);
  EXPECT_CALL(eepM, clear())
             .Times(AtLeast(1))
             .WillOnce(Return(true));
  //act
  int ret = myDB.initDataBase();
  //assert
  EXPECT_EQ(1, ret);
}

TEST(MyDBTest, writeTest){
  //arrange
  EEPROMMock eepM;
  MyDataBase myDB(eepM);
  EXPECT_CALL(eepM, write(444,_))
             .Times(AtLeast(1))
             .WillOnce(Return(true));
  //act
  int ret = myDB.writeDataBase(78);
  //assert
  EXPECT_EQ(1, ret);
}

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}