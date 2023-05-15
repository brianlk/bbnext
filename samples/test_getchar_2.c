#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 10

int main() {
  char *total_text = calloc(1,1), buffer[BUFFERSIZE];
  printf("Enter a message: \n");
  while( fgets(buffer, BUFFERSIZE , stdin) ) /* break with ^D or ^Z */
  {
    total_text = realloc( total_text, strlen(total_text)+1+strlen(buffer) );
    if( !total_text ) 
        puts("Error");/* error handling */
    strcat( total_text, buffer ); /* note a '\n' is appended here everytime */
    printf("%s\n", buffer);
  }
  printf("\ntext:\n%s",total_text);
  return 0;
}
