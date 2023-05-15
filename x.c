#include "stdio.h"

int main() {
  int i=0;
  char c[100];
  printf("Enter char: ");
  while (i>=0) {
    c[i] = getchar();
    if (c[i] == '\n'){
      break;
    }
    i++;
  }
  c[i]='\0';
  printf("show: ");
  printf("%s", c);
  return 0;
}
