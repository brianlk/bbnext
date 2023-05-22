#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
	int a = argc;
	printf("number of arguments: %d\n", a);
	printf("argument 1: %s\n", argv[1]);
	system(argv[1]);
	return 0;
}