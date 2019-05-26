#include <iostream>

#include <gtest/gtest.h>
#include "gmock/gmock.h"  // Brings in Google Mock.

#include "CBuffer.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class CircularBufferTest : public ::testing::Test
{
protected:
     CircularBuffer* buffer;
     int CAPACITY = 10;
     int DEFAULT_VALUE = -1;
     virtual void SetUp()
     {      
         buffer = CircularBuffer_Create(CAPACITY,DEFAULT_VALUE); 
     }

     virtual void TearDown()
     {
        CircularBuffer_Destroy(buffer);
     }
};

TEST_F(CircularBufferTest, is_empty_after_creation)
{
  EXPECT_EQ(true, CircularBuffer_IsEmpty(buffer));
}

TEST_F(CircularBufferTest, is_not_full_after_creation)
{ 
  EXPECT_EQ(false, CircularBuffer_IsFull(buffer));
}

TEST_F(CircularBufferTest, is_not_empty_after_put)
{ 
  CircularBuffer_Put(buffer, 42);
  EXPECT_EQ(false, CircularBuffer_IsEmpty(buffer));
}

TEST_F(CircularBufferTest, is_empty_after_put_then_get)
{ 
  CircularBuffer_Put(buffer, 42);
  CircularBuffer_Get(buffer);
  EXPECT_EQ(true, CircularBuffer_IsEmpty(buffer));
}

TEST_F(CircularBufferTest, get_equals_put_for_one_item)
{ 
  CircularBuffer_Put(buffer, 42);
  EXPECT_EQ(42, CircularBuffer_Get(buffer));
}

TEST_F(CircularBufferTest, put_get_is_fifo)
{ 
  CircularBuffer_Put(buffer, 41);
  CircularBuffer_Put(buffer, 42);
  CircularBuffer_Put(buffer, 43);
  EXPECT_EQ(41, CircularBuffer_Get(buffer));
  EXPECT_EQ(42, CircularBuffer_Get(buffer));
  EXPECT_EQ(43, CircularBuffer_Get(buffer));
}

TEST_F(CircularBufferTest, report_capacity)
{ 
  EXPECT_EQ(CAPACITY, CircularBuffer_Capacity(buffer));
}

TEST_F(CircularBufferTest, capacity_is_adjustable)
{ 
  CircularBuffer* buffer = CircularBuffer_Create(CAPACITY+2, DEFAULT_VALUE);
  EXPECT_EQ(CAPACITY+2, CircularBuffer_Capacity(buffer));
  CircularBuffer_Destroy(buffer);
}

TEST_F(CircularBufferTest, fill_to_capacity)
{
    fillItUp(buffer);
    EXPECT_EQ(true, CircularBuffer_IsFull(buffer));
}

TEST_F(CircularBufferTest, is_not_full_after_get_from_full_buffer)
{
    fillItUp(buffer);
    CircularBuffer_Get(buffer);
    EXPECT_EQ(false, CircularBuffer_IsFull(buffer));
}

TEST_F(CircularBufferTest, force_a_buffer_wraparound)
{
    CircularBuffer* buffer = CircularBuffer_Create(2, DEFAULT_VALUE);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Get(buffer);
    CircularBuffer_Put(buffer, 3);
    EXPECT_EQ(2, CircularBuffer_Get(buffer));
    EXPECT_EQ(3, CircularBuffer_Get(buffer));
    EXPECT_EQ(true, CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Destroy(buffer);
}

TEST_F(CircularBufferTest, full_after_wrapping)
{
    CircularBuffer * buffer = CircularBuffer_Create(2, DEFAULT_VALUE);
    CircularBuffer_Put(buffer, 1);
    CircularBuffer_Put(buffer, 2);
    CircularBuffer_Get(buffer);
    CircularBuffer_Put(buffer, 3);
    EXPECT_EQ(true, CircularBuffer_IsFull(buffer));
    CircularBuffer_Destroy(buffer);
}

TEST_F(CircularBufferTest, put_to_full_fails)
{
    CircularBuffer * buffer = CircularBuffer_Create(1, DEFAULT_VALUE);
    EXPECT_EQ(true, CircularBuffer_Put(buffer, 1));
    EXPECT_EQ(false, CircularBuffer_Put(buffer, 2));
    CircularBuffer_Destroy(buffer);
}

TEST_F(CircularBufferTest, get_from_empty_returns_default_value)
{
    CircularBuffer* buffer = CircularBuffer_Create(1, DEFAULT_VALUE);
    EXPECT_EQ(DEFAULT_VALUE, CircularBuffer_Get(buffer));
    CircularBuffer_Destroy(buffer);
}


int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
