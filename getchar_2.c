#include "stdio.h"
#include "string.h"

int main() {
    char output[5];
    char out2[10] = "xxx";
    int first_init, last_init;
    printf("What are your two initials?\n");
    first_init = getchar();
    last_init = getchar();
    output[0] = (char)first_init;
    output[1] = (char)last_init;
    printf("%s\n", output);
    strcat(out2, output);
    printf("%s\n", out2);
    return 0;
}
