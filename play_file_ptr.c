#include "stdio.h"
#include "stdlib.h"

void write(FILE* fptr);
void read(FILE* fptr);

int main() {
	FILE* fptr;
	// write(fptr);
	read(fptr);
}

void write(FILE* fptr) {
	fptr = fopen("/tmp/x.file", "w");
	if (!fptr) {
		printf("Error: failed to open file.\n");
		exit (1);
	}
	fprintf(fptr, "i am ok.");
	fclose(fptr);
}

void read(FILE* fptr) {
	int c;
	char line[81];
	fptr = fopen("/tmp/x.file", "r");
	while (1) {
		c = fgetc(fptr);
		if (feof(fptr))
			{break;}
		printf("%c", c);
	}
	fclose(fptr);
}
