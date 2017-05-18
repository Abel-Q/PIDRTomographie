
#test : test.c retroproj.o
#	gcc -Wall test.c retroproj.o -o test `pkg-config opencv --libs`

#retroproj.o : retroproj.c
#	gcc -c retroproj.c -Wall `pkg-config opencv --cflags`


retroprojection : main.c retroproj.o
	gcc -Wall main.c retroproj.o  -o retroprojection -lm

retroproj.o : retroproj.c
	gcc -c retroproj.c -Wall -lm

#filtre.o : filtre.c
#	gcc -lfftw3 -lm -Wall -c filtre.c

clear :
	rm *.o
