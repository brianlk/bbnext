#include "stdio.h"
#include "stdlib.h"

#define MEMINFO "/proc/meminfo"

int main() {
	FILE *fp;
	int ch;

	// open "/proc/meminfo"
	fp = fopen(MEMINFO, "r");
	if (fp == NULL) {
		puts("Error: Can't open the file!");
		exit(1);
	}
	// Read the file until eof
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n') {
			break;
		}
		putchar(ch);
	}
	fclose(fp);

	return(0);
}