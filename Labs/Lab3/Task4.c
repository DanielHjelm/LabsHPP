#include <stdio.h>

int CmpDouble (const void* p1, const void* p2) {
	if (*(double*)p1 < *(double*)p2) {
		return -1;
	}
	else if (*(double*)p1 == *(double*)p2) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	double arrDouble[] = {9.3, -2.3, 1.2, -0.4, 2, 9.2, 1, 2, 0};
	int arrDoubleLen = sizeof(arrDouble) / sizeof(double);
	qsort (arrDouble, arrDoubleLen, sizeof(double), CmpDouble);

	for (int i = 0; i < arrDoubleLen; i++) {
		printf("%f ", arrDouble[i]);
	}
}