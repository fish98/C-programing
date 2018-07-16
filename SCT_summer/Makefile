matrix.o : matrix.h
	gcc matrix.c -c -lm  
	make main
main : main.c matrix.o
	gcc main.c matrix.o -o main -lm -O2 -march=native
	echo -e "\nExcute main to Start\n"
	rm matrix.o
clean: 
	rm matrix.o main


