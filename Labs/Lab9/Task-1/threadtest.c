#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* the_thread_func(void* arg) {
  /* Do something here? */
  int* p = (int*)malloc(2*sizeof(int));
  p[0] = 0;
  p[1] = 1;

  return p;  //either we return it
  // pthread_exit(p);  //or we use pthread_exit
}

int main() {
  printf("This is the main() function starting.\n");

  /* Start thread. */
  pthread_t thread;
  printf("the main() function now calling pthread_create().\n");
  if(pthread_create(&thread, NULL, the_thread_func, NULL) != 0) {
    printf("ERROR: pthread_create failed.\n");
    return -1;
  }

  printf("This is the main() function after pthread_create()\n");

  /* Do something here? */
  int* d = (int*)malloc(2*sizeof(int));

  /* Wait for thread to finish. */
  printf("the main() function now calling pthread_join().\n");
  if(pthread_join(thread, &d) != 0) {
    printf("ERROR: pthread_join failed.\n");
    return -1;
  }
  printf("%d \n", d[1]);
  free(d);
  
  return 0;
}
