#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MEMINFO "/proc/meminfo"
#define BUFFERSIZE 64

int main() {
	FILE *fp;
	char buffer[BUFFERSIZE];

	// open "/proc/meminfo"
	fp = fopen(MEMINFO, "r");
	if (fp == NULL) {
		puts("Error: Can't open the file!");
		exit(1);
	}
	// Read the file until eof
	while (!feof(fp)) {
		fgets(buffer, BUFFERSIZE, fp);
		if (buffer == NULL)
			break;
		// grep the related string
		char *target = strndup(buffer, 5);	
		if (strcmp(target, "MemTo") == 0){
			printf("%s\n", target);
		}
		if (strcmp(target, "MemFr") == 0){
			printf("%s\n", target);
		}
	}
	fclose(fp);

	return(0);
}