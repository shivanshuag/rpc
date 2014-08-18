#include <stdlib.h>
#include "day.h"


int * leap_1_svc(int * year, struct svc_req * req){
	printf("called\n");
	int i;
	int leapYears = 0;
	for(i=1;i<(*year);i++){
		if( (i%400 == 0) || (i%4 == 0 && i%100 != 0) )
			leapYears++;
	}

	return(&leapYears);
}