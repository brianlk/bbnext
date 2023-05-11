#include "stdlib.h"
#include "stdio.h"
#include "time.h"

int main(){
    int i, n;
    time_t t;
    n = 5;
    srand(time(&t));
    for (i=0; i<n; i++) {
        printf("%d\n", rand()%90);
    }
}
