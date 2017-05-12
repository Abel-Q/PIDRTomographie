
test : test.c retroproj.o
	gcc -Wall test.c retroproj.o -o test `pkg-config opencv --libs`

retroproj.o : retroproj.c
	gcc -c retroproj.c -Wall `pkg-config opencv --cflags`
