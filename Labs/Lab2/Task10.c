#include <stdio.h>
#include <stdlib.h>

void print_array(int *, int );


int main()
{
    int *arr;
    int n;
    printf("Enter the number of variablies in the list: ");
    scanf("%d", &n);
    arr = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; ++i) 
        arr[i] = rand() % 100; // random number from 0 to 99
    print_array(arr, n);
    return 0;
}

void print_array(int *arr, int n) {
        
    printf("Elements of given array: \n");   
    //Loop through the array by incrementing value of i     
    for (int i = 0; i < n; i++) {     
        printf("%d\n ", arr[i]);     
    }      
}