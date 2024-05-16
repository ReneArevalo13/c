//
// Created by Rene Arevalo on 5/7/24.
//
#include <stdio.h>

enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
struct date {enum month m; int d;} date;
// hold months in string array
static const char * const month_name[] = {
    "January",  "February", "March",
    "April",    "May",      "June",
    "July",     "August",   "September",
    "October",  "November", "December",
};

void printdate(struct date date) {
    printf("%s %d \n", month_name[date.m], date.d);
}

struct date next_day(struct date date) {
    // logic to handle the end of months
    // handle months with 31 days
    if (date.m == 0 || date.m == 2 || date.m == 4 || date.m == 6
        || date.m == 7 || date.m == 9 || date.m == 11) {

        if (date.m == 11 && date.d == 31) {
            date.m = 0;
            date.d = 1;
            return date;
        }
        if (date.d == 31) {
            date.m++;
            date.d = 1;
            return date;
        }
        date.d++;
        return date;
    }
    // handle months with 30 days
    if (date.m == 3 || date.m == 5 || date.m == 8 || date.m == 10) {
        if (date.d == 30) {
            date.m++;
            date.d = 1;
        }
        date.d++;
        return date;
    }
    // handle february with 28 days
    if (date.m == 1) {
        if (date.d == 28) {
            date.m++;
            date.d = 1;
        }
        return date;
    }
    return date;
}

int main(void) {

    struct date date1 = {jan, 1};
    struct date date2 = {feb, 28};
    struct date date3 = {mar, 14};
    struct date date4 = {oct, 31};
    struct date date5 = {dec, 31};
    printdate(date1);
    printdate(next_day(date1));
    printdate(date2);
    printdate(next_day(date2));
    printdate(date3);
    printdate(next_day(date3));
    printdate(date4);
    printdate(next_day(date4));
    printdate(date5);
    printdate(next_day(date5));
    return 0;
}