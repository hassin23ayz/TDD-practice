#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

//#include <inttypes.h>

#define UTC_BASE_YEAR     1970
#define MONTH_PER_YEAR    12
#define DAY_PER_YEAR      365
#define SEC_PER_DAY       86400
#define SEC_PER_HOUR      3600
#define SEC_PER_MIN       60

typedef struct mytime_struct
{
    unsigned int nYear;
    unsigned int nMonth;
    unsigned int nDay;
    unsigned int nHour;
    unsigned int nMin;
    unsigned int nSec;
    unsigned int DayIndex; /* 0 = Sunday */
};

unsigned long mytime_2_utc_sec(struct mytime_struct *currTime, unsigned char daylightSaving);

#endif // FIZZBUZZ_H
