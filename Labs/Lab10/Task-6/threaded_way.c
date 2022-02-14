#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int is_prime(int N) {
	int j;
	for (j = 2; j<N; j++) {
		if (N%j == 0) {
			return 0;
		}
	}
	//printf("%d is prime \n", N);
	return 1;
}

typedef struct thread_data {
   int start;
   int stop;
   int result;
} thread_data;

void thread_func(thread_data* tdata) {
  /* Do something here? */
  int start = tdata->start;
  int stop = tdata->stop;
  int amount = 0;
  int i;

  for (i = start; i<stop; i++) {
  	amount += is_prime(i);
  }

  tdata->result=amount;
}

int main(int argc, const char * argv[]) {
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	thread_data thread_datas[M];

	#ifdef _OPENMP
		printf("openMP is supported \n");
	#else
    	M = 1;
	#endif

	printf("N: %d, M: %d \n", N, M);

	int i;

	//the threads
	for (i = 0; i < M; i++) {
		thread_datas[i].start = (i*N)/M;
		thread_datas[i].stop = ((i+1)*N)/M;
		thread_datas[i].result = 0;
	}
	
	#pragma omp parallel num_threads(M)
  {
    /* OK, now we are inside the parallel block, so this is executed
       by several threads. Get ID of current thread. */
  	int id = 0;
  	#ifdef _OPENMP
		id = omp_get_thread_num();
	#endif
    /* Call thread_func and give it a pointer to arr[id] as input. */
    thread_func(&thread_datas[id]);
  }

  	int sum = -2;  //since 0 and 1 is not prime
	sum += is_prime(N);

	for (i = 0; i < M; i++) {
		sum += thread_datas[i].result;
	}
	printf("primes: %d \n", sum);
}
