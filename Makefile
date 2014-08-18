.SUFFIXES:
.SUFFIXES: .c .o
CLNT = day
SRVR_1 = day_svc_1
SRVR_2 = day_svc_2
SRVR_3 = day_svc_3

CFLAGS = -g -Wall

SRVR_OBJ_1 = day_svc_proc_1.o day_xdr.o day_svc_1.o
SRVR_OBJ_2 = day_svc_proc_2.o day_xdr.o day_svc_2.o
SRVR_OBJ_3 = day_svc_proc_3.o day_xdr.o day_svc_3.o

CLNT_OBJ = day.o day_xdr.o day_clnt.o

.c.o:; gcc -c -o $@ $(CFLAGS) $<

default: $(CLNT) $(SRVR_1) $(SRVR_2) $(SRVR_3)

$(CLNT): $(CLNT_OBJ) day.h
	gcc -o $(CLNT) $(CLNT_OBJ)

$(SRVR_1): $(SRVR_OBJ_1) day.h
	gcc -o $(SRVR_1) $(SRVR_OBJ_1)

$(SRVR_2): $(SRVR_OBJ_2) day.h
	gcc -o $(SRVR_2) $(SRVR_OBJ_2)

$(SRVR_3): $(SRVR_OBJ_3) day.h
	gcc -o $(SRVR_3) $(SRVR_OBJ_3)

clean:
	rm *.o $(CLNT) $(SRVR)
	rm -i *~
	rm core
