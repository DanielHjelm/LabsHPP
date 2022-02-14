#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct thread_data {
   int ID;
} thread_data;

thread_data thread_datas[6];
pthread_t threads[6];

void* the_thread_func(void* arg) {
	thread_data *tdata=(thread_data *)arg;
	int ID = tdata->ID;
	printf("Thread: %d \n", ID);

	if (ID == 0 || ID == 3) {
		thread_datas[ID+1].ID = ID+1;
		thread_datas[ID+2].ID = ID+2;

		pthread_create(&threads[ID+1], NULL, the_thread_func, (void *)&thread_datas[ID+1]);
		pthread_create(&threads[ID+2], NULL, the_thread_func, (void *)&thread_datas[ID+2]);

	}
	pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {

	printf("Main Thread\n");
	
	thread_datas[0].ID = 0;
	thread_datas[3].ID = 3;

	pthread_create(&threads[0], NULL, the_thread_func, (void *)&thread_datas[0]);
	pthread_create(&threads[3], NULL, the_thread_func, (void *)&thread_datas[3]);

	pthread_exit(NULL);
}