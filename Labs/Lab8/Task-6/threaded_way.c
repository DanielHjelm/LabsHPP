#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// Prime function
int is_prime(int N) {
	int j;
	for (j = 2; j<N; j++) {
		if (N%j == 0) {
			return 0;
		}
	}
	return 1;
}

// Struct defining thread data
// Here we use a starting point, stop point and the result
typedef struct thread_data {
   int start;
   int stop;
   int result;
} thread_data;

void* the_thread_func(void* arg) {
  thread_data *tdata=(thread_data *)arg;
  int start = tdata->start;
  int stop = tdata->stop;
  int amount = 0;
  int i;

  for (i = start; i<stop; i++) {
  	amount += is_prime(i);
  }

  tdata->result=amount;
  pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	thread_data thread_datas[M];
	pthread_t threads[M];

	int i;

	//the threads
	for (i = 0; i < M; i++) {
		thread_datas[i].start = floor((i*N)/M);
		thread_datas[i].stop = floor(((i+1)*N)/M);
		thread_datas[i].result = 0;
		pthread_create(&threads[i], NULL, the_thread_func, (void *)&thread_datas[i]);
	}

	int sum = -2;  //since 0 and 1 is not prime
	for (i = 0; i < M; i++) {
		pthread_join(threads[i], NULL);
		sum += thread_datas[i].result;
	}
	sum += is_prime(N);
	printf("primes: %d \n", sum);
}
