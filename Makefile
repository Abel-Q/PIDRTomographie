
#test : test.c retroproj.o
#	gcc -Wall test.c retroproj.o -o test `pkg-config opencv --libs`

#retroproj.o : retroproj.c
#	gcc -c retroproj.c -Wall `pkg-config opencv --cflags`


test : test.c retroproj.o filtre.o
	gcc -Wall test.c retroproj.o filtre.o -o test -lm -lfftw3

retroproj.o : retroproj.c
	gcc -c retroproj.c -Wall -lm

filtre.o : filtre.c
	gcc -lfftw3 -lm -Wall -c filtre.c

clear :
	rm *.o
