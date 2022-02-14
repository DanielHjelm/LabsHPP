#include <stdio.h>
#include <math.h>

int main() {
	float a = 1.0;
	double b = 1.0;

	do {
		a = a*100;
		b = b*100;
		printf("a is: %f \n", a);
		printf("b is: %f \n", b);
	}
	while (!isinf(b) || !isinf(a));
	printf("sqrt(-1) = %f \n", sqrt(-1));
	printf("a + b = %f \n", a + b);
	printf("sqrt(-1) + 1 = %f \n", sqrt(-1) + 1);
}

