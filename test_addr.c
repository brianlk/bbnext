#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
	int age = 100;
	int* age_p;
	age_p = &age;
	printf("%p", age_p);
	(*age_p) = 101;
	printf("%d", age);

	// dynamic mem allocation
	int* ptr = (int*)malloc(1000000 * sizeof(int));
	ptr[0] = 10000;
}