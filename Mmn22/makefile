mycomp: mycomp.o complex.o check_syntax.o 
	gcc -ansi -Wall -pedantic mycomp.o complex.o check_syntax.o -o mycomp -lm

mycomp.o:  mycomp.c mycomp.h
	gcc -c -ansi -Wall -pedantic mycomp.c -o mycomp.o

complex.o:  complex.c complex.h
	gcc -c -ansi -Wall -pedantic complex.c -o complex.o

check_syntax.o:  check_syntax.c mycomp.h
	gcc -c -ansi -Wall -pedantic check_syntax.c -o check_syntax.o

clean:
	rm -f mycomp.o complex.o check_syntax.o mycomp
