#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main() {
	int ccc[10];
  ccc[0] = 'a';
  ccc[1] = 'b';
  ccc[2] = 'c';

  char* out_str = malloc(20);
  printf("%p\n", out_str);
  *out_str = ccc[0];
  out_str++;

  printf("Next address: %p\n", out_str);
  *out_str = ccc[1];
  out_str++;

  printf("Next address: %p\n", out_str);
  *out_str = ccc[2];
  out_str++;

  *out_str = '\0';
  printf("Next address: %p\n", out_str);

  // pointer go back to begining
  out_str -= 3;
  printf("First address: %p\n", out_str);
  printf("%s", out_str);
}
