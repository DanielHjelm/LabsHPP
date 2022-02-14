#include <stdio.h>

int main () {
   int i, j, a, b;

   printf("Enter row size: ");
   scanf("%d", &a);

   printf("Enter column size: ");
   scanf("%d", &b);

   /* Iterate through each row */
    for(i=1; i<=a; i++)
    {
        /* Iterate through each column */
        for(j=1; j<=b; j++)
        {
            if (i ==1 || i == a || j == 1 || j == b) {
                printf("*");
            }
            /* For each column print star */
            else {
                printf(".");
            }
        }
        
        /* Move to the next line/row */
        printf("\n");
    }
   
   return 0;
}