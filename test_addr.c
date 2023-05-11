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

	// print array name
	int arr[3] = {1,2,3};
	printf("arr name pointer constant: %p\n", arr);
	printf("first element address: %p\n", &arr[0]);

  // c_arr is pointer constant and cannot be changed
	char c_arr[100] = "i am okay";
	printf("%s\n", c_arr);
	// dereference a pointer c_arr = first char
	printf("%c\n", *c_arr);
	printf("%p\n", c_arr);
	// use char pointer and string assginment without strcopy
  // c_p is not a constant so it can be changed.
	char* c_p = "i am okay";
	printf("%s\n", c_p);
	printf("%c\n", c_p[0]);
	printf("%p\n", c_p);
	c_p = "i am not okay";
	printf("%s\n", c_p);
	printf("%p\n", c_p);
}
