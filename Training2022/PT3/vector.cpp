// $ g++ test.cpp -lgtest -lgtest_main -pthread
// $ ./a.out

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

// DUT 
// Stack is FILO / LIFO (like pile of books)
class Stack {
  vector<int> v;
public:
  // Constructor
  Stack() {}

  // Destructor
  ~Stack() {}

  // Perform a binary operation on two operands and return the result
  void put(int elem) 
  {
    v.push_back(elem;)
  }

  int get(void)
  {
    
  }
};

// this type is DUT's fixture type 
struct ALU_F : public testing::Test{
    ALU* pAlu;
    void SetUp()
    {
        pAlu = new ALU();
    }
    void TearDown()
    {
        delete pAlu;
    }
};

// this test case works with pre instantiated DUT object with the help of fixture 
TEST_F(ALU_F, add_2_nums)
{
    int result = pAlu->operate(2,3, '+');
    //verify
    ASSERT_EQ(result, 5);
}

// this test case creates the DUT object and works on it 
TEST(ALU_test, add_2_nums)
{
    //setup
    ALU mAlu;
    //exercise
    int result = mAlu.operate(2,3, '+');
    //verify
    ASSERT_EQ(result, 5);
    //cleanup
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}