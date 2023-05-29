#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h" 


#define MEMINFO "/proc/meminfo"
#define BUFFERSIZE 64



bool extract_lines(FILE *fp) {
	char buffer[BUFFERSIZE];
	
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
	return true;
}



int main() {
	FILE *fp;

	// open "/proc/meminfo"
	fp = fopen(MEMINFO, "r");
	if (fp == NULL) {
		puts("Error: Can't open the file!");
		exit(1);
	}
	extract_lines(fp);
	fclose(fp);

	return(0);
}