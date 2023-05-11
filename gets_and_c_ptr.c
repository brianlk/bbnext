#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
	char* c_p = (char*)malloc(100 * sizeof(char));
	fgets(c_p, 60, stdin);
	printf("%s", c_p);
	puts(c_p);
}