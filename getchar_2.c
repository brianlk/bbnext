#include "stdio.h"
#include "string.h"

int main() {
    int first_init, last_init;
    printf("What are your two initials?\n");
    first_init = getchar();
    last_init = getchar();
    printf("%c", (char)first_init);
    printf("%c", (char)last_init);
}
