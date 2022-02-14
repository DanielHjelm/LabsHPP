#include "testfuncs.h"

void f_std(const double * __restrict a, 
	   const double * __restrict b, 
	   double * __restrict c, int N) {
  int i;
  int counter = 0;
  double x = 0;
  for(i = 0; i < N; i++) {
    if(counter == 4) {
      x += 0.1;
      counter = 0;
    }
    c[i] = a[i]*a[i] + b[i] + x;
    counter++;
  }
}

// void f_opt(const double * __restrict a, 
// 	   const double * __restrict b, 
// 	   double * __restrict c, int N) {
//   int i;
//   int counter = 0;
//   double x = 0;
//   for(i = 0; i < N; i++) {
//     if(counter == 4) {
//       x += 0.1;
//       counter = 0;
//     }
//     c[i] = a[i]*a[i] + b[i] + x;
//     counter++;
//   }
// }

void f_opt(const double * __restrict a, 
	   const double * __restrict b, 
	   double * __restrict c, int N) {
  int i;
  int j;
  double x = 0;
  for(i = 0; i < N; i+=4) {
    c[i] = a[i]*a[i] + b[i] + x;
    j = i + 1;
    c[j] = a[j]*a[j] + b[j] + x;
    j++;
    c[j] = a[j]*a[j] + b[j] + x;
    j++;
    c[j] = a[j]*a[j] + b[j] + x;
    x += 0.1;
  }
}


