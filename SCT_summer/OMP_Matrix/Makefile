matrix.o : matrix.h
	gcc matrix.c -c -lm  -fopenmp
	make main
main : main.c matrix.o
	gcc main.c matrix.o -o main -lm -O2 -march=native -fopenmp
	echo -e "\nExcute main to Start\n"
	rm matrix.o
clean: 
	rm main



