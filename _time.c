#include "head.h"
#include "_time.h"
#include "func.h"

const char *CONVERT_DAY_OR_MONTH[] = {
    "00",
    "01",
    "02",
    "03",
    "04",
    "05",
    "06",
    "07",
    "08",
    "09"
};

typedef struct tm Date;

char *get_current_time()
{
    time_t t = time(NULL);
    struct tm *n_time = localtime(&t);
    char *tstr = (char *)malloc(sizeof(char) * MAX_CHAR);
    char day[3];
    char month[3];

    if(n_time->tm_mday < 10)
        strcpy(day, CONVERT_DAY_OR_MONTH[n_time->tm_mday]);
    else
        sprintf(day,"%d",n_time->tm_mday);

    if(n_time->tm_mon+1 < 10)
        strcpy(month, CONVERT_DAY_OR_MONTH[n_time->tm_mon+1]);
    else
        sprintf(month,"%d",n_time->tm_mon);
    sprintf(tstr,"%d%s%s",n_time->tm_year+1900,month,day);
    return tstr;
}


Date pack_date(const char *str)
{
    Date d;
    d.tm_year = atoi(split(str,0,4)) - 1900;
    d.tm_mon  = atoi(split(str,4,6)) - 1;
    d.tm_mday = atoi(split(str,6,8));
    return d;
}


int diff_day(const char *day1, const char *day2)
{
    long t;
    Date tm1,tm2;
    tm1 = pack_date(day1);
    tm2 = pack_date(day2);
    t=(long)difftime(mktime(&tm1), mktime(&tm2));
    return(abs(t/24/3600));
}
