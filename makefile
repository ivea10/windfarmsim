tas.o : tas.h tas.c
	gcc -c tas.c

test_tas.o : tas.h test_tas.c
	gcc -c test_tas.c

test_tas : tas.o test_tas.o
	gcc tas.o test_tas.o -o test_tas
