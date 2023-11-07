#include <stdio.h>
#include "convert_integer.h"

// custom floor function
long my_floor(double number);
int calculate_ordinal_day(int day, int month , int year);
int is_leap_year(int year);
int get_day_of_week_first_jan(int year);
int calculate_ISO_week(int ordinal_daya, int week_day, int year);
int weeks_in_year(int year);
void get_ordinal_date(int day, int month , int year);
void get_week_date(int day,int month, int year);
void get_calendar_date(int day, int month, int year);


int p(int year);

int main(){

    int day,month,year;

    // get the input from stdin for day, month and the year
    day = get_integer();
    month = get_integer();
    year = get_integer();

    // call the printing functions
    get_calendar_date(day,month,year);
    get_ordinal_date(day,month,year);
    get_week_date(day,month,year);
    return 0;
}


long my_floor(double  number){
    // check number is negative
    if(number < 0 )
        return (long)number - 1;    // get the integer part and reduce 1
    else
        return (long) number;       // only get the intege rpart by casting
}

// Implement the algorithms
int is_leap_year(int year){
    // return true if year is divisible by 400 or divisible by 4 while not 100
    return (((year % 4 == 0) && (year % 100!= 0)) || (year % 400 == 0));
}

int calculate_ordinal_day(int day, int month , int year){
    if(month == 1)
        return day;
    if(month == 2)
        return day + 31;

    long ordinal_day = my_floor(30.6 *month - 91.4) + day;

    if (is_leap_year(year))
        return ordinal_day + 60;

    return ordinal_day + 59;

}

void get_ordinal_date(int day, int month , int year){
    printf("%i-%03d\n",year, calculate_ordinal_day(day,month,year));
}

int get_day_of_week_first_jan(int year){
    return   (1 + 5 * ((year-1) % 4) + 4 * ((year-1) % 100) + 6 * ((year-1) % 400)) % 7;
}

int calculate_ISO_week(int ordinal_day, int week_day, int year){
    int week = my_floor((ordinal_day - week_day + 10) /7);

    if (week == 0)
        week = weeks_in_year(year - 1);

    if (week > weeks_in_year(year)) {
        if (week_day < 4)
            week = 1;
    }

    return week;
}

int p(int year){
    return (year + (year / 4) - (year / 100) + (year / 400) ) % 7;
}

int weeks_in_year(int year){
    if (p(year) == 4 || p(year-1) == 3)
        return 53;
    else
        return 52;
}

void get_week_date(int day,int month, int year){
    int ordinal_day = calculate_ordinal_day(day,month,year);
    int week_day = (get_day_of_week_first_jan(year) -1+ ordinal_day)  % 7;
    if (week_day == 0){
        week_day = 7;
    }
    int week_number = calculate_ISO_week(ordinal_day,week_day,year);
    if (month == 12 && week_number == 1){
        year++;
    }
    if (month == 1 && (week_number == 52 || week_number == 53)){
        year--;
    }

    printf("%i-W%02d-%i\n",year, week_number,week_day);
}

void get_calendar_date(int day, int month, int year){
    printf("%i-%02d-%02d\n",year,month,day);
}

