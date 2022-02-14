#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct t_data {
   int start;
   int stop;
   double sum;
   double dx;
} t_data;

void* thread_func(void* arg) {
	double sum, dx, x;
	t_data *data=(t_data *)arg;
	int start = data->start;
	int stop = data->stop;
	dx = data->dx;
	sum = data->sum;

	int i;
	printf("start: %d and stop: %d \n", start, stop);
	for (i = start; i < stop; i++) { 
    	x = dx*(i - 0.5);
    	sum += dx*4.0/(1.0 + x*x);
  	}
  	data->sum = sum;
  	//printf("thread sum: %f \n", sum);
  	pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
    // Fetch the number of threads you want
	int N = atoi(argv[1]);
	double sum, dx, x;

	t_data thread_datas[N];
	pthread_t threads[N];

	const int intervals = 500000000;
	dx  = 1.0/intervals;
    sum = 0;
    

	// Creating the loops
	int i;
	for (i = 0; i < N; i++) {
		thread_datas[i].start = floor((i*intervals)/N);
		thread_datas[i].stop = floor(((i+1)*intervals)/N);
		thread_datas[i].sum = 0;
		thread_datas[i].dx = dx;
		pthread_create(&threads[i], NULL, thread_func, (void *)&thread_datas[i]);
	}

	
	// Joining the loops and adding to sum
	for (i = 0; i < N; i++) {
		pthread_join(threads[i], NULL);
		sum += thread_datas[i].sum;
	}
	// Last one
	x = dx*(intervals - 0.5);
    sum += dx*4.0/(1.0 + x*x);

	printf("Approximate Pi: %.16f\n", sum);
    printf("Actual Pi: %.16f\n", M_PI);
}


