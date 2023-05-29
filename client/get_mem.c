#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "regex.h"


#define MEMINFO "/proc/meminfo"
#define BUFFERSIZE 64

const char *metrics[] = {
	"MemTo",
	"MemFr",
	"MemAv",
	"SwapT",
	"SwapF",
	"Cache"

};

bool match_regex(char *str) {
	regex_t regex;
	int reg_comp = regcomp(&regex, "[0-9]", 0);
	if (reg_comp != 0) {
		printf("Error:");
	}
	int reg_exec = regexec(&regex, str, 0, NULL, 0);
	if (reg_exec == 0) {
		return true;
	}
	return false;
}


char* extact_values(char *str) {
	char *delimiter = " ";
	char *token;

	token = strtok(str, delimiter);
	while (token != NULL) {
		if (match_regex(token)) {
			return token;
		}
		token = strtok(NULL, delimiter);
	}
}

bool extract_items(FILE *fp) {
	char buffer[BUFFERSIZE];

	// Read the file until eof
	while (!feof(fp)) {
		fgets(buffer, BUFFERSIZE, fp);
		if (buffer == NULL)
			break;
		// loop the metrics array and get the metrics
		char *target = strndup(buffer, 5);
		int array_size = sizeof(metrics)/sizeof(metrics[0]);
		for (int i=0; i<array_size; i++) {
			if (strcmp(target, metrics[i]) == 0){
				// extract the value of each memory item
				printf("%s, %s\n", buffer, extact_values(buffer));
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
	if ( extract_items(fp) ) {
		printf("Extract info ok\n");
	}
	fclose(fp);

	return(0);
