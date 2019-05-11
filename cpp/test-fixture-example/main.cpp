// sq-root.cpp

#include <iostream>
using namespace std;

#include "whattotest.cpp"
#include <gtest/gtest.h>

#include <stdio.h> 
#include <string.h> 

class DataSource
{
public:
	char dataSrcStr[256];
	char okSubStr[8];
	char errorSubStr[8];
	DataSource()
	{
		memset(dataSrcStr, '\0', 256);
		memset(okSubStr, '\0', 8);
		memset(errorSubStr, '\0', 8);

		strcpy(okSubStr, "OK");
		strcpy(errorSubStr, "ERROR");
	}

	void putStrArray(char* _strToBePut)
	{
		strcpy(dataSrcStr, _strToBePut);
	}
};

struct DataSourceTest : public testing::Test
{
protected:
	DataSource* myDataSrc;
	void SetUp()
	{ 
		myDataSrc = new DataSource(); 
		myDataSrc->putStrArray("ERROR   OK");
	}
	void TearDown(){ delete myDataSrc; }
};

TEST_F(DataSourceTest, testWithSpace)
{
	EXPECT_EQ(true, findString((uint8_t*)myDataSrc->dataSrcStr, myDataSrc->okSubStr, 512));
}

//bool findString(uint8_t* mainStr, const char* subStr, uint32_t maxlen)
 
TEST(FindString, MainStrIsBiggerThanSubStr) 
{
	//arrange
	uint8_t mainStr[] = "++23==OKABCDEF";
	char subStr[] = "OK";
	//act 
	//assert
	EXPECT_EQ(true, findString(mainStr, subStr, 512));
	// EXPECT_EQ(true, findString(mainStr, subStr, 8)); 
	// EXPECT_EQ(true, findString(mainStr, subStr, 6)); 
	// EXPECT_EQ(true, findString(mainStr, subStr, 2));
	
}

TEST(FindString, mismatchTest) 
{
	uint8_t mainStr[] = "OKABCDEF";
	char subStr2[] = "ERROR";

	EXPECT_EQ(false, findString(mainStr, subStr2, 0));
}

TEST(FindString, mixedTest) 
{
	uint8_t mainStr[] = "OK+ERROREF";
	uint8_t mainStr2[] = "+++ERROREF";
	uint8_t mainStr3[] = "OKERROR";

	char subStr[] = "ERROR";

	EXPECT_EQ(true, findString(mainStr, subStr, 512));
	EXPECT_EQ(true, findString(mainStr2, subStr, 512));
	EXPECT_EQ(true, findString(mainStr3, subStr, 512));
}

TEST(FindString, MainStrIsSmallerThanSubStr) 
{
	//arrange
	uint8_t mainStr[] = "O";
	char subStr[] = "OK";
	//act 
	//assert
	EXPECT_EQ(false, findString(mainStr, subStr, 512));
}

TEST(FindString, MainStrWithoutNulTermination)
{
	//arrange 
	uint8_t mainStr[7] = {'O','K','E','R','R','O','R'};
	uint8_t subStr[] = "OK";
	char subStr2[] = "OK";
	//assert
	EXPECT_EQ(true, findString(mainStr, (const char*)subStr, 512));
	EXPECT_EQ(true, findString(mainStr, subStr2, 512));
}

// TEST(FindString, subStrNull)
// {
// 	//arrange 
// 	uint8_t mainStr[7] = {'O','K','E','R','R','O','R'};
// 	//assert
// 	EXPECT_EQ(false, findString(mainStr, NULL, 512));
// }

TEST(CLibFunTest, strLenFunc)
{
	uint8_t mainStr[7] = {'O','K','E','R','R','O','R'};
	char mainStr2[9] = {'O','K','E','R','R','O','R','p','\0'};

	EXPECT_EQ(7, strlen((char*)mainStr));
	EXPECT_EQ(8, strlen(mainStr2));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}