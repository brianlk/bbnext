#include "stdlib.h"
#include "stdio.h"
#include "string.h"


int main() {
  int* i_ptr = (int*) malloc(1000);
  float* f_ptr = (float*) malloc(1000);
  double* d_ptr = (double*) malloc(1000);
  char* c_ptr = (char*)malloc(1000);
  char* x = "hello world!";
  char y[100];
  strcpy(y, x);
  y[0] = '1';
  printf("%s\n", y);
}

