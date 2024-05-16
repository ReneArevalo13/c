/*
Create Months and Date
*/

#include <stdio.h>

typedef enum month{January,
                February,
                March,
                April,
                May,
                June,
                July,
                August,
                September,
                October,
                November,
                December} month;

typedef struct date
{
    month m;
    int d;
} date;

// Takes date as input and returns the next date
date nextday(date dt)
{
    int n_day = dt.d + 1;
    struct date next_day;
    next_day.d = n_day;
    next_day.m = dt.m;
    return next_day;
}

// Takes date as input and prints it
void printdate(date dt) {
    month current_month = dt.m;
    int most_days; // most number of days that month can have
    switch (current_month) {
        case January:
            most_days = 31;
            if(dt.d <= most_days)
                printf("Date: January %d\n", dt.d);
            break;
        case February:
            most_days = 28;
            if(dt.d <= most_days)
                printf("Date: February %d\n", dt.d);
            break;
        case March:
            most_days = 31;
            if(dt.d <= most_days)
                printf("Date: March %d\n", dt.d);
            break;
        case April:
            most_days = 30;
            if(dt.d <= most_days)
                printf("Date: April %d\n", dt.d);
            break;
        case May:
            most_days = 31;
            if(dt.d <= most_days)
                printf("Date: May %d\n", dt.d);
            break;
        case June:
            most_days = 30;
            if(dt.d <= most_days)
                printf("Date: June %d\n", dt.d);
            break;
        case July:
            most_days = 31;
            if(dt.d <= most_days)
                printf("Date: July %d\n", dt.d);
            break;
        case August:
            most_days = 31;
            if(dt.d <= most_days)
                printf("Date: August %d\n", dt.d);
            break;
        case September:
            most_days = 30;
            if(dt.d <= most_days)
                printf("Date: September %d\n", dt.d);
            break;
        case October:
            most_days = 31;
            if(dt.d <= most_days)
                printf("Date: October %d\n", dt.d);
            break;
        case November:
            most_days = 30;
            if(dt.d <= most_days)
                printf("Date: November %d\n", dt.d);
            break;
        case December:
            most_days = 31;
            if(dt.d <= most_days)
                printf("Date: December %d\n", dt.d);
            break;
        default:
            printf("Invalid date\n");
            break;
    }
}

int main()
{
    // Januart 1
    enum month m1 = January;
    struct date d1;
    d1.m = m1;
    d1.d = 1;

    // February 2
    enum month m2 = February;
    struct date d2;
    d2.m = m2;
    d2.d = 28;

    // March 14
    enum month m3 = March;
    struct date d3;
    d3.m = m3;
    d3.d = 14;

    // October 31
    enum month m4 = October;
    struct date d4;
    d4.m = m4;
    d4.d = 31;

    // December 31
    enum month m5 = December;
    struct date d5;
    d5.m = m5;
    d5.d = 31;

    printdate(d1);
    printdate(nextday(d1));

    printdate(d2);
    printdate(nextday(d2));

    printdate(d3);
    printdate(nextday(d3));

    printdate(d4);
    printdate(nextday(d4));

    printdate(d5);
    printdate(nextday(d5));

    return 0;
}