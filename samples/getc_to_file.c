#include "stdio.h"

int main() {
  FILE *fp;
  char s[20] = "i am okay";
  char c;
  
  fp = fopen("/tmp/file.txt", "w");
  while (1) {
    c = getc(stdin);
    if (c == EOF) {
      break;
    }
    fputc(c, fp);
  }
  fclose(fp);
  return 0;
}
