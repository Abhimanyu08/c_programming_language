#include <stdio.h>


static char daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};


int day_of_year(int year, int d, int m) {
    
    int i;
    char* days;

    int day;
    if (year % 4 == 0 && !(year%100 == 0 && year%400 != 0)) {
	days = daytab[1];
    } else {
	days = daytab[0];
    }

    day =0;

    for (i = 0; i < m; i++) {
	printf("%d\n", (int)*(days+i));
	day += (int)*(days + i);	
    }

    day += d;
    return day;

}


void month_day(int year, int yearday, int* m, int* d) {

    char* days;
    
    if (year % 4 == 0 && !(year%100 == 0 && year%400 != 0)) {
	days = daytab[1];
    } else {
	days = daytab[0];
    }

    int i;

    for (i = 0; yearday > (int)*(days+i); i++)
	yearday -= (int)*(days + i);

    *m = i;
    *d = yearday;

}


main() {

    int day;
    day = day_of_year(2024, 5, 3);
    int month;
    int monthday;

    printf("day: %d\n", day);
    month_day(2024, 65, &month, &monthday);
    printf("month: %d\t day: %d\n", month, monthday);
}
