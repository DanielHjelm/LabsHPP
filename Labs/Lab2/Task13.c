#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file;
	file = fopen("data.txt","r");
	if (file) {
		char line[20];
	while (fread(line, sizeof(line), sizeof(line),file)) {
		printf("%s", line); 
	}
	fclose(file);
	}
}