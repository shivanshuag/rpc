#include <stdlib.h>
#include "day.h"

int * computation_1_svc(int * days, struct svc_req * req){
	printf("called\n");
	int left = (*days)%7;
	return(&left);
}