#include "unity.h"

#include "fizzbuzz.h"
#include "stdbool.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// void test_if_3_then_green(void)
// {
//     //TEST_ASSERT_EQUALIGNORE_MESSAGE("Need to Implement fizzbuzz");
//     TEST_ASSERT_EQUAL(1,2);
// }

void test_if_today_is_okay(void)
{
	struct mytime_struct timeNow = {2020, 1, 21, 19, 37, 0, 2};
	//printf("current time in unix = %lu\n\r", mytime_2_utc_sec(&timeNow, 0));
    TEST_ASSERT_EQUAL(1579635420,mytime_2_utc_sec(&timeNow, 0));
}

void test_if_qa_input_time_okay(void)
{
	struct mytime_struct timeNow = {2020, 1, 21, 18, 10, 16, 2};
    TEST_ASSERT_EQUAL(1579630216,mytime_2_utc_sec(&timeNow, 0));
}

void test_start_threshold_is_okay(void)
{
	struct mytime_struct timeNow = {2020, 3, 1, 0, 0, 0, 2};
    TEST_ASSERT_EQUAL(1583020800,mytime_2_utc_sec(&timeNow, 0));
}


void test_time_is_always_forwarded(void)
{
	struct mytime_struct thresTS = {2019, 1, 1, 0, 0, 0, 2};
	unsigned long threshold = mytime_2_utc_sec(&thresTS, 0);

	bool alwaysForward = true;
	for(uint16_t year = 2019; year <= 2021; year++)
	{
		for(uint8_t month = 1; month <= 12; month++)
		{
			uint8_t dateLimit = 30;
			if(month == 2) {dateLimit = 28;}

			for(uint8_t date = 1; date <= dateLimit; date++)
			{
				for(uint8_t hour = 0; hour <= 23; hour++)
				{
					for(uint8_t min = 0; min <= 59; min++)
					{
						for(uint8_t sec = 1; sec <= 59; sec++)
						{
							struct mytime_struct simTime = {year, month, date, hour, min, sec};
							unsigned long SimTimeUnix = mytime_2_utc_sec(&simTime, 0);

							//printf("SimTimeUnix = %lu\n\r", SimTimeUnix);
							//TEST_ASSERT_GREATER_THAN(threshold, SimTimeUnix);
							if(SimTimeUnix > threshold){
								threshold = SimTimeUnix;
								//printf(".\n\r");
							}
							else{
								printf("prob found at simTime = %lu\n\r", SimTimeUnix);
								alwaysForward = false;
							}						
						}//sec
					}//min				
				}//hour
			}//date
		}//month
	}//year

	TEST_ASSERT_EQUAL(true,alwaysForward);
}