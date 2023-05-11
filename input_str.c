#include "stdio.h"

int main() {
    char input[100];
    char ans;
    printf("Please input a string\n");
    fgets(input, 20, stdin);
    printf("Are you sure your name %s?", input);
    ans = getchar();
    if (ans == 'y')
    {
        printf("OK\n");
    }
}
