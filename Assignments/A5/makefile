mymatrix: main.c matrix.o bstree.o datatype.o
	gcc -o mymatrix main.c matrix.o bstree.o datatype.o

matrix.o: matrix.c matrix.h
	gcc -c matrix.c

bstree.o: bstree.c bstree.h
	gcc -c bstree.c

datatype.o: datatype.c datatype.h
	gcc -c datatype.c

clean:
	rm -f *.o core