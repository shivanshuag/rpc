#include <stdio.h>
#include "day.h"


int main(int argc, char *argv[])
{

    CLIENT *cl_1;
    CLIENT *cl_2;
    CLIENT *cl_3;

    if (argc < 2){
        printf("Insufficient Arguments");
        return 1;
    }

    cl_1 = clnt_create(argv[1], DAYPROG1, DAYPROGVERS, "tcp");
    if (cl_1 == NULL) {
        printf("error: could not connect to server1.\n");
        return 1;
    }

    cl_2 = clnt_create(argv[2], DAYPROG2, DAYPROGVERS, "tcp");
    if (cl_2 == NULL) {
        printf("error: could not connect to server2.\n");
        return 1;
    }

    cl_3 = clnt_create(argv[3], DAYPROG3, DAYPROGVERS, "tcp");
    if (cl_3 == NULL) {
        printf("error: could not connect to server3.\n");
        return 1;
    }

    char input, day_string[3], month_string[3], year_string[18];
    int counter = 0;
    scanf("%c",&input);
    while(input != '/'){
        day_string[counter] = input;
        scanf("%c",&input);
        counter++;
    }
    day_string[counter] = '\0';
    counter = 0;
    scanf("%c",&input);
    while(input != '/'){
        month_string[counter] = input;
        scanf("%c",&input);
        counter++;
    }
    month_string[counter] = '\0';
    counter = 0;
    scanf("%c",&input);
    while(input != '\n'){
        year_string[counter] = input;
        scanf("%c",&input);
        counter++;
    }
    year_string[counter] = '\0';

    int year;
    int month,day;
    day = atoi(day_string);
    month = atoi(month_string);
    year = atol(year_string);

    int * leap;
    if(month > 2){
    	long int send = year + 1;
    	leap = leap_1(&send, cl_1);
    }
    else
    	leap = leap_1(&year, cl_1);
    date * newDate;
    newDate = (date *)malloc(sizeof(date));
    newDate->years = year;
	newDate->months = month;
	newDate->days = day;
	newDate->leap = *leap;
    int *totalDays;
    totalDays = days_1(newDate, cl_2);
    int *dayOfWeek ;
    dayOfWeek = computation_1(totalDays, cl_3);
    switch(*dayOfWeek){
        case(0):
            printf("Monday");
            break;
        case(1):
            printf("Tuesday");
            break;
        case(2):
            printf("Wednesday");
            break;
        case(3):
            printf("Thursday");
            break;
        case(4):
            printf("Friday");
            break;
        case(5):
            printf("Saturday");
            break;
        case(6):
            printf("Sunday");
            break;
    }
    return 0;
}
