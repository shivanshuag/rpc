#include <stdlib.h>
#include "day.h"



 int * days_1_svc(date * newDate, struct svc_req * req){
	printf("called\n");
	 int years = newDate->years;
	printf("years %d\n", years);
	int months = newDate->months;
	int days = newDate->days;
	 int leap = newDate->leap;
	 int totalDays = 0;
	totalDays = 365*(years -1);
	printf("total %d\n", totalDays);
	switch(months){
		case 1:
			totalDays += 0;
			break;
		case 2:
			totalDays += 31;
			break;
		case 3:
			totalDays += 59;
			break;
		case 4:
			totalDays += 90;
			break;
		case 5:
			totalDays += 120;
			break;
		case 6:
			totalDays += 152;
			break;
		case 7:
			totalDays += 182;
			break;
		case 8:
			totalDays += 212;
			break;
		case 9:
			totalDays += 243;
			break;
		case 10:
			totalDays += 273;
			break;
		case 11:
			totalDays += 304;
			break;
		case 12:
			totalDays += 334;
			break;
	}
	totalDays += (days + leap - 1);
	printf("final total %d\n", totalDays);
	return (&totalDays);

}
