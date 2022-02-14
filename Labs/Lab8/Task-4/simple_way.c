#include <stdio.h>
#include <stdlib.h>

int is_prime(int N) {
	int j;
	for (j = 2; j<N; j++) {
		if (N%j == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, const char * argv[]) {
	int N = atoi(argv[1]);
	int i;
	int j;
	int amount = 0;

	for (i = 2; i <= N; i++) {
		amount += is_prime(i);
	}
	printf("primes: %d \n", amount);
}
