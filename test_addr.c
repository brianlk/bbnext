#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
	int age = 100;
	int* age_p;
	age_p = &age;
	// print age addreess
	printf("age address: %p\n", age_p); 
	// print pointer of age address
	printf("pointer of age address: %p\n", &age_p);
	(*age_p) = 101;
	printf("%d", age);

	// dynamic mem allocation
	int* ptr = (int*)malloc(1000000 * sizeof(int));
	ptr[0] = 10000;
}