#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Struct defining thread data
typedef struct thread_data {
   int ID;
} thread_data;

// Thread function
void* the_thread_func(void* arg) {
	thread_data *tdata=(thread_data *)arg;
	int ID = tdata->ID;
	printf("Thread %d \n", ID);
	pthread_exit(NULL);
	}

int main(int argc, const char * argv[]) {
	// Read number of threads
	int N = atoi(argv[1]);
	// Create thread data
	thread_data thread_datas[N];

	int i;
	for (i = 0; i < N; i++) {
		// Create thread
		pthread_t thread;    
		// Set thread data    
		thread_datas[i].ID = i;
		// Create thread
		pthread_create(&thread, NULL, the_thread_func, (void *)&thread_datas[i]);
	}
	// Exit threads
	pthread_exit(NULL); 
}