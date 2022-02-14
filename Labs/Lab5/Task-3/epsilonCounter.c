#include <stdio.h>

int main() {
	float a = 1.0;
	double b = 1.0;

	do {
		a = a*0.5;
		b = b*0.5;
		printf("a is: %f \n", a);
		printf("b is: %f \n", b);
		printf("1 < 1 + a: %d \n", 1 < 1+a);
		printf("1 < 1 + b: %d \n", 1 < 1+b);
        printf("\n");
	}
	while (1 < 1+b || 1 < 1+a);
}