#include <stdio.h>

void print_int_1(int x) {
	printf("Here is the number: %d\n", x);
}

void print_int_2(int x) {
	printf("Wow, %d is really an impressive number!\n", x);
}

int main() {
	//creates a pointer foo that points to print_int_1
	void (*foo)(int);
	foo = print_int_1;
	foo(3);

	//then we want to point it at print_int_2
	foo = print_int_2;
	foo(4);
}