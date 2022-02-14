matmul: matmul.c
	gcc -Wall -O3 -o matmul matmul.c

matmulParallell: matmulParallell.c
	gcc -Wall -O3 -o matmulParallell matmulParallell.c -lpthread

clean:
	rm -f matmul matmul_parallell
