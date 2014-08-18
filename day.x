struct date {
	int years;
	int months;
	int days;
	int leap;
};

program DAYPROG1 {
    version DAYPROGVERS {
    	int LEAP(int) = 1;
 	} = 1;
} = 0x20000001;

program DAYPROG2 {
    version DAYPROGVERS {
    	int DAYS(date) = 2;
 	} = 1;
} = 0x20000002;

program DAYPROG3 {
    version DAYPROGVERS {
    	int COMPUTATION(int) = 3;
 	} = 1;
} = 0x20000003;

