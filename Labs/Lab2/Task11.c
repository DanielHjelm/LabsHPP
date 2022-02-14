#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int *arr;
	int n = 1;
	arr = (int *)malloc(n*sizeof(int));
	int flag = 1;
	do {
		fgets(arr[n-1], sizeof(int), stdin);
		n++;
		(int *)realloc(arr,n*sizeof(int));
	}
	while (flag);
	
	print_array(arr, n);
	return 0; 
}