#include "stdio.h"
#include "string.h"

int test_func(int x);


int main() {
	int o;
	char c_arr[20] = "i am okay.";
	for (int i=0; i<strlen(c_arr); i++) {
		int x = test_func((int)c_arr[i]);
		printf("%d => %c\n", x, c_arr[i]);
	}
	return 0;
}

int test_func(int x) {
	return x;
}