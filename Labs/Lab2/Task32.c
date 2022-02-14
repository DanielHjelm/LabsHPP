#include <stdio.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main() {
    int n, a, b, c;

   printf("Enter the first integer: ");
   scanf("%d", &a);

   printf("Enter the second integer: ");
   scanf("%d", &b);

   printf("Enter the third integer: ");
   scanf("%d", &c);

    int array[] = {a, b, c};
    qsort(array, 5 , sizeof(int), cmpfunc);

    printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {   
      printf("%d ", array[n]);
   }
   
    return 0;
}

