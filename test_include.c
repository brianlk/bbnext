#include "stdio.h"
#include "string.h"

int test_func(int x);
void test_array_addr();

int main() {
	int o;
	char c_arr[20] = "i am okay.";
	for (int i=0; i<strlen(c_arr); i++) {
		int x = test_func((int)c_arr[i]);
		printf("%d => %c\n", x, c_arr[i]);
	}
	test_array_addr();
	return 0;
}

int test_func(int x) {
	return x;
}

void test_array_addr() {
	int x[10] = {1,2,3};
	printf("element 0 addr: %p\n", &x[0]);
	printf("element 1 addr: %p\n", &x[1]);
	printf("element 2 addr: %p\n", &x[2]);
  x[0]= 100000;
  (*&x[0]) = 10;
  printf("%d", x[0]);
}
