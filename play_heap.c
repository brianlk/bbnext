#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
	// create heap and check the memory usage
	int* temp;
	temp = (int*) malloc(400000000); // number of elements x size of int
	for (int j=0; j<10000000; j++) {
		temp[j] = 10000;
	}
	free(temp);
	for (;;) {

	}
	// free(temp);
}

