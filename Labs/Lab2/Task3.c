#include <stdio.h>
int main() {
    int a, b, product, sum;

   printf("Enter the first integer: ");
   scanf("%d", &a);

   printf("Enter the second integer: ");
   scanf("%d", &b);

   if (a % 2 == 0 && a % 2 == 0) {
    product = a * b;
    printf("Product of the two even integers = %d\n", product);
   }
   else {
       sum = a + b;
       printf("Sum of the two integers = %d\n", sum);
   }
    return 0;
}