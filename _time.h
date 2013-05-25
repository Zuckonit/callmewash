#ifndef _TIME_H
#define _TIME_H
#include <time.h>

typedef struct tm Date;
char *get_current_time();
int diff_day( const char *day1, const char *day2);
Date pack_date(const char *str);

#endif
