#include "stdio.h"
#include "string.h"

int main() {
    int i;
    int msg[25];
    printf("Input 10 chars: ");
    for (int i=0; i<25; i++){
        msg[i]=getchar();
        if (msg[i] == '\n'){
            i--;
            break;
        }
    }
    for (int i=0;i<25;i++) {
        printf("%d => %c\n", msg[i], msg[i]);
    }
    putchar('\n');
    return 0;
}
    