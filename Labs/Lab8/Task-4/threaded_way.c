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
	return 1;
}

typedef struct thread_data {
   int N;
   int result;
} thread_data;

void* the_thread_func(void* arg) {
  /* Do something here? */
  thread_data *tdata=(thread_data *)arg;
  int N = tdata->N;
  int amount = 0;
  int i;

  for (i = floor(N/2); i<=N; i++) {
  	amount += is_prime(i);
  }

  tdata->result=amount;
  pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
	int N = atoi(argv[1]);
	int i;
	int amount = 1;   //two is a prime number

	//the thread
	pthread_t thread;
	thread_data tdata;
	tdata.N = N;
	tdata.result = 0;
	pthread_create(&thread, NULL, the_thread_func, (void *)&tdata);

	for (i = 3; i < N/2; i++) {   //thread will take the other half
		amount += is_prime(i);
	}
	pthread_join(thread, NULL);
	printf("primes: %d \n", amount + tdata.result);
}
