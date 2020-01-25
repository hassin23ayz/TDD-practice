#include "fizzbuzz.h"

unsigned char g_day_per_mon[MONTH_PER_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*****************************************************
* Function   : applib_dt_is_leap_year
* Description: Calculating leap or flat years
* Input      : 
* Output     :     
* Other      :      
******************************************************/


unsigned char applib_dt_is_leap_year(unsigned short year)
{
    if ((year % 400) == 0) 
		{
        return 1;
    } 
		else if ((year % 100) == 0)
		{
        return 0;
    } 
		else if ((year % 4) == 0) 
		{
        return 1;
    } 
		else 
		{
        return 0;
    }
}

/*****************************************************
* Function   : applib_dt_last_day_of_mon
* Description: 
* Input      : 
* Output     :     
* Other      :      
******************************************************/
unsigned char applib_dt_last_day_of_mon(unsigned char month, unsigned short year)
{
    if ((month == 0) || (month > 12)) 
		{
        return g_day_per_mon[1] + applib_dt_is_leap_year(year);
    }

    if (month != 2)
		{
        return g_day_per_mon[month - 1];
    } 
		else 
		{
        return g_day_per_mon[1] + applib_dt_is_leap_year(year);
    }
}

/*****************************************************
* Function   : mytime_2_utc_sec
* Description: local time to unix time
* Input      : 
* Output     :     
* Other      :      
******************************************************/
unsigned long mytime_2_utc_sec(struct mytime_struct *currTime, unsigned char daylightSaving)
{
    unsigned int i = 0;
    unsigned int  no_of_days = 0;
    unsigned long utc_time =0;
	unsigned long temp =0;
    unsigned char dst = 0;

    if (currTime->nYear < UTC_BASE_YEAR) 
		{
        return 0;
    }

    /* year */
    for (i = UTC_BASE_YEAR; i < currTime->nYear; i++) 
		{
        no_of_days += (DAY_PER_YEAR + applib_dt_is_leap_year(i));
    }
    //DBG_PRINTF("no_of_days=%d\n",no_of_days);
		
    /* month */
    for (i = 1; i < currTime->nMonth; i++) 
		{
        no_of_days += applib_dt_last_day_of_mon((unsigned char) i, currTime->nYear);
    }
    //DBG_PRINTF("no_of_days=%d\n",no_of_days);
    /* day */
    no_of_days += (currTime->nDay - 1);
		
    //DBG_PRINTF("no_of_days=%d\n",no_of_days);
		
    /* sec */
    
		//utc_time = (unsigned int) no_of_days * SEC_PER_DAY + 
		//					 (unsigned int) (currTime->nHour * SEC_PER_HOUR +currTime->nMin * SEC_PER_MIN + currTime->nSec);
    //DBG_PRINTF("utc_time=%ld\n",utc_time);
		
		utc_time = utc_time  + ((unsigned long)no_of_days * SEC_PER_DAY);
				
		utc_time = (utc_time  + ((unsigned long)currTime->nHour * SEC_PER_HOUR));
		

		utc_time = utc_time  + ((unsigned long)currTime->nMin * SEC_PER_MIN);
		
		utc_time = utc_time  +((unsigned long)currTime->nSec);
		
		
    if (dst && daylightSaving)
		{
        utc_time -= SEC_PER_HOUR;
    }
	
    //DBG_PRINTF("utc_time=%ld\n",utc_time);
    
		return utc_time;
}
