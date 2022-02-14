#include <omp.h>
#include <stdio.h>

long int N = 500000000;

void funcA() {
  long int i;
  double x = 1.0;
  for(i = 0; i < N; i++)
    x *= 1.000000001;
  printf("funcA() result: x = %f\n", x);
}

void funcB() {
  long int i;
  double x = 1.0;
  for(i = 0; i < N; i++)
    x *= 1.000000002;
  printf("funcB() result: x = %f\n", x);
}

int main(int argc, char *argv[]) {

#pragma omp parallel num_threads(2)
  {

#pragma omp sections
    {

#pragma omp section
      {
	funcA();
      }

#pragma omp section
      {
	funcB();
      }

    } /* end of omp sections block */

  } /* end of omp parallel block */

  return 0;
}
