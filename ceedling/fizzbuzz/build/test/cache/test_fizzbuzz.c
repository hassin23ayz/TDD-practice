#include "build/temp/_test_fizzbuzz.c"
#include "src/fizzbuzz.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}















void test_if_today_is_okay(void)

{

 struct mytime_struct timeNow = {2020, 1, 21, 19, 37, 0, 2};



    UnityAssertEqualNumber((UNITY_INT)((1579635420)), (UNITY_INT)((mytime_2_utc_sec(&timeNow, 0))), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}



void test_if_qa_input_time_okay(void)

{

 struct mytime_struct timeNow = {2020, 1, 21, 18, 10, 16, 2};

    UnityAssertEqualNumber((UNITY_INT)((1579630216)), (UNITY_INT)((mytime_2_utc_sec(&timeNow, 0))), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}



void test_start_threshold_is_okay(void)

{

 struct mytime_struct timeNow = {2020, 3, 1, 0, 0, 0, 2};

    UnityAssertEqualNumber((UNITY_INT)((1583020800)), (UNITY_INT)((mytime_2_utc_sec(&timeNow, 0))), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}





void test_time_is_always_forwarded(void)

{

 struct mytime_struct thresTS = {2019, 1, 1, 0, 0, 0, 2};

 unsigned long threshold = mytime_2_utc_sec(&thresTS, 0);



 

_Bool 

     alwaysForward = 

                     1

                         ;

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







       if(SimTimeUnix > threshold){

        threshold = SimTimeUnix;



       }

       else{

        printf("prob found at simTime = %lu\n\r", SimTimeUnix);

        alwaysForward = 

                       0

                            ;

       }

      }

     }

    }

   }

  }

 }



 UnityAssertEqualNumber((UNITY_INT)((

1

)), (UNITY_INT)((alwaysForward)), (

((void *)0)

), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);

}
