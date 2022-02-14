#include <stdio.h>
#include <pthread.h>

void* the_thread_func(void* arg) {
  printf("thread_func starting doing some work.\n");
  long int i;
  double sum = 0;
  for(i = 0; i < 1000000000; i++)
    sum += 2e-7;
  printf("Result of work in thread_func: sum = %f\n", sum);
  return NULL;
}

void* the_thread_funcB(void* arg) {
  printf("thread_funcB starting doing some work.\n");
  long int i;
  double sum;
  for(i = 0; i < 1000000; i++) {
    sum += 3e-7;
  }
  printf("Result of work in thread_funcB: sum = %f\n", sum);
  return NULL;
}

int main() {
  printf("This is the main() function starting.\n");

  /* Start thread. */
  pthread_t thread;
  pthread_t threadB;

  printf("the main() function now calling pthread_create().\n");
  pthread_create(&thread, NULL, the_thread_func, NULL);
  pthread_create(&threadB, NULL, the_thread_funcB, NULL);

  printf("This is the main() function after pthread_create()\n");

  printf("main() starting doing some work.\n");
  long int i;
  double sum;
  for(i = 0; i < 1000000000; i++)
    sum += 1e-7;
  printf("Result of work in main(): sum = %f\n", sum);

  /* Wait for thread to finish. */
  printf("the main() function now calling pthread_join().\n");
  pthread_join(thread, NULL);

  return 0;
}
