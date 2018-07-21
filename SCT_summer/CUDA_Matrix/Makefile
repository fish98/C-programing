matrix.o : matrix.h
	nvcc matrix.cu -c -lm  
	make main
main : main.cu matrix.o
	nvcc main.cu matrix.o -o main -lm -O2
	echo -e "\nExcute main to Start\n"
	rm matrix.o
clean: 
	rm main



