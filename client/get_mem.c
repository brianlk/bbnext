#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h" 


#define MEMINFO "/proc/meminfo"
#define BUFFERSIZE 64

const char *metrics[] = {
	"MemTo",
	"MemFr"
};	

bool extract_lines(FILE *fp) {
	char buffer[BUFFERSIZE];

	// Read the file until eof
	while (!feof(fp)) {
		fgets(buffer, BUFFERSIZE, fp);
		if (buffer == NULL)
			break;
		// grep the related string
		char *target = strndup(buffer, 5);
		for (int i=0; i<2; i++) {
			if (strcmp(target, metrics[i]) == 0){
				printf("%s\n", target);
			}
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
	if ( extract_lines(fp) ) {
		printf("Extract info ok\n");
	}
	fclose(fp);

	return(0);
}