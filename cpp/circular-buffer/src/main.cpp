#include <iostream>

#include <gtest/gtest.h>
#include "gmock/gmock.h"  // Brings in Google Mock.

#include "CBuffer.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST(CircularBuffer, clearBufferCheck)
{
  //setup
  clear();
  //exercise
  bool emptyAns = isEmpty();
  //verify
  EXPECT_EQ(emptyAns, true);
  //cleanup
}


TEST(CircularBuffer, emptyCheck){
  //setup
  //exercise
  bool emptyAns = isEmpty();
  //verify
  EXPECT_EQ(emptyAns, true);
  //cleanup
  //setup
  //exercise
  put('a');
  bool emptyAns2 = isEmpty();
  //verify
  EXPECT_EQ(emptyAns2, false);
  //cleanup
  clear();
}

TEST(CircularBuffer, emptyBuffRead)
{
  //setup
  //exercise
  bool emptyAns = isEmpty();
  ASSERT_EQ(emptyAns, true);
  int value = get();
  //verify
  EXPECT_EQ(value, -1);
  //cleanup
  clear();
}

TEST(CircularBuffer, putOneElementToEmptyBuffer)
{
  //setup
  put('a');
  //exercise
  int value = get();
  //verify
  EXPECT_EQ(value, 'a');
  //cleanup
  clear();
  //exercise
  int value2 = get();
  //verify
  EXPECT_EQ(value2, -1);
}

TEST(CircularBuffer, putMultipleElementsReadOnce)
{
  //setup
  clear();
  put('a');
  put('b');
  put('c');
  //exercise
  int value = get();
  //verify
  EXPECT_EQ(value, 'a');
  //cleanup
  clear();
}

TEST(CircularBuffer, putMultipleElementsReadOneByOne)
{
  //setup
  clear();
  put('a');
  int firstValue = get();
  EXPECT_EQ(firstValue, 'a');

  put('b');
  int secondValue = get();
  EXPECT_EQ(secondValue, 'b');

  put('c');
  int thirdValue = get();
  EXPECT_EQ(thirdValue, 'c');

  clear();
}

TEST(CircularBuffer, putMultipleElementsReadOutOfPut)
{
  //setup
  clear();
  put('a');
  put('b');

  //exercise
  int firstValue = get();
  int secondValue = get();
  int thirdValue = get();

  //verify
  EXPECT_EQ(firstValue, 'a');
  EXPECT_EQ(secondValue, 'b');
  EXPECT_EQ(thirdValue, -1);

  //cleanup
  clear();
}

TEST(CircularBuffer, putMultipleElementsReadAll)
{
  //setup
  clear();
  put('a');
  put('b');
  put('c');
  //exercise
  int firstValue = get();
  int secondValue = get();
  int thirdValue = get();
  //verify
  EXPECT_EQ(firstValue, 'a');
  EXPECT_EQ(secondValue, 'b');
  EXPECT_EQ(thirdValue, 'c');
  //cleanup
  clear();
}


TEST(CircularBuffer, putMultipleElementsWithOverflow)
{
  //setup
  clear();
  put('a');
  put('b');
  put('c');
  put('d');
  put('e');  
  //exercise
  int firstValue = get();
  int secondValue = get();
  int thirdValue = get();
  //verify
  EXPECT_EQ(firstValue, 'a');
  EXPECT_EQ(secondValue, 'b');
  EXPECT_EQ(thirdValue, 'c');
  //cleanup
  clear();
}

TEST(CircularBuffer, putMultipleReadOutOFboundary)
{
  //setup
  clear();
  put('a');
  put('b');
  put('c');
  put('d');
  //exercise
  int firstValue = get();
  int secondValue = get();
  int thirdValue = get();
  int fourthValue = get();
  int fifthValue = get();
  //verify
  EXPECT_EQ(fifthValue, -1);

  put('e');
  put('f');

  int sixthValue = get();
  int seventhValue = get();

  EXPECT_EQ(sixthValue, 'e');
  EXPECT_EQ(seventhValue, 'f');

  //cleanup
  clear();
}

TEST(CircularBuffer, putMultipleReadMixed)
{
  //setup
  clear();
  put('a');
  put('b');
  put('c');
  //exercise
  int firstValue = get();
  int secondValue = get();
  put('d');
  int thirdValue = get();
  put('e');
  int fourthValue = get();
  int fifthValue = get();
  //verify
  EXPECT_EQ(thirdValue, 'c');
  EXPECT_EQ(fourthValue, 'd');
  EXPECT_EQ(fifthValue, 'e');
  //cleanup
  clear();
}

TEST(CircularBuffer, putMinusOneInBetween)
{
  //setup
  clear();
  put('a');
  put('b'); 
  put(-1);
  put('c');
  //exercise

  int firstValue = get();
  int secondValue = get();
  int thirdValue = get();
  //verify
  EXPECT_EQ(firstValue, 'a');
  EXPECT_EQ(secondValue, 'b');
  EXPECT_EQ(thirdValue, 255);
  //cleanup
  clear();  
}

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}