/*=============================================================================
#     FileName: wash.c
#         Desc:
#       Author: Mocker
#        Email: Zuckerwooo@gmail.com
#     HomePage: zuckonit.github.com
#      Version: 0.0.1
#   LastChange: 2013-05-25 17:21:54
#      History:
=============================================================================*/

#include "io.h"
#include "head.h"
#include "_time.h"

#define MSG_GOOD "=3\n"     /*message if you have washed the clothes*/
#define MSG_BAD  "╭(╯^╰)╮\n"   /*message if you have not washed the clothes*/
#define APPNAME  "callmewash"

const char *f_record = "days.txt";    /*file to record the days after your last washing*/
const char *f_date = "date.txt";      /*file to record the date of your last running this program*/

int input(char ch)
{
    switch(ch) {
    case 'y':        /*when input y or Y return 0*/
    case 'Y':
        return 0;
    case 'n':        /*when input n or N return 1*/
    case 'N':
        return 1;
    default:         /*other invalidate input return 2*/
        return 2;
    }
}


void welcome()  /*welcome content when you running the program*/
{
    printf( "\t\t\t\t+============================\n");
    printf( "\t\t\t\t|%s\n",APPNAME);
    printf( "\t\t\t\t|\t\t_by Zuckonit\n");
    printf( "\t\t\t\t+============================\n");
}


int plus_day()
{
    char *buf = read_file(f_record);
    int day = atoi(buf);
    char str[MAX_CHAR];
    int _day;
    if (day == 0) {
        printf("Error data (integer instead) have been existed in %s", f_record);
        exit(1);
    }
    _day = diff_day(buf, get_current_time());
    if (_day > 1)
        day = _day;
    else
        day++;
    sprintf(str, "%d", day);
    write_file(f_record, str);
    return day;
}


int update_date()
{
    char *c_date = get_current_time();
    if (!file_exist(f_date)) {
        write_file(f_date, c_date);
        return 1;
    }
    char *r_date = read_file(f_date);
    if(strcmp(c_date, r_date) != 0) {
        write_file(f_date, c_date);
        return 1;
    }
    return 0;
}


void init()
{
    if(!file_exist(f_record)) {
        write_file(f_record, "1");
    }
}


int main(int argc, const char *argv[])
{
    char ch;
    int res;

    welcome();
    init();
    if(!update_date()) {
        printf("You have checked today!");
        exit(1);
    }
    printf("%s days after your last washing!\n",read_file(f_record));
    printf("Have you washed your clothes? (Y/N)/(y/n): ");
    ch = getchar();
    getchar();
    res = input(ch);
    if(res == 0) {
        printf(MSG_GOOD);
        write_file(f_record, "1");
        update_date();
    }
    else if(res == 1) {
        printf(MSG_BAD);
        plus_day();
        update_date();
    }
    else
        printf("Error input, only (Y/N)/(y/n) admitted!\n");
    return 0;
}
