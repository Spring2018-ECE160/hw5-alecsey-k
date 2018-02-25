#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

// day of year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == year%100 != 0 || year%400 == 0;

    if (month < 1 || month > 12)
    {
        printf("ERROR: %d is not a valid entry for month.\n", month);
        return 0;
    }
    if (day < 1)
    {
        printf("ERROR: Day cannot be zero or negative.\n");
        return 0;
    }
    if (day > daytab[leap][month])
    {
        printf("ERROR: %d is not a day in %d/%d.\n", day, month, year);
        return 0;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

// month_day: set month, day from day of year
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday < 1)
    {
        printf("ERROR: Day cannot be zero or negative.\n\n");
        return 1;
    }
    if ((leap == 0 && yearday > 365) || (leap == 1 && yearday > 366))
    {
        printf("ERROR: %d is not a day in the year %d.\n\n", yearday, year);
        return 1;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    return 0;
}

int main()
{
    int day1;
    printf("13/30/2017\n");
    day1 = day_of_year(2017, 13, 30);
    printf("Day 1 = %d\n\n", day1);

    int day2;
    printf("2/-1/2018\n");
    day2 = day_of_year(2018, 2, -1);
    printf("Day 2 = %d\n\n", day2);

    int day3;
    printf("2/29/2018\n");
    day3 = day_of_year(2018, 2, 29);
    printf("Day 3 = %d\n\n", day3);

    int pmonth1, pday1;
    printf("Day -1 in 2018\n");
    month_day(2018, -1, &pmonth1, &pday1);

    int pmonth2, pday2;
    printf("Day 366 in 2018\n");
    month_day(2018, 366, &pmonth2, &pday2);

    return 0;
}
