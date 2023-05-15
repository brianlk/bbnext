#include "stdio.h"
#include "string.h"
#include "test_c_include.h"


int main() {
    char month[6] = "April";
//    printf("I am ok");
//    printf("%s %d %f %c\n", month, 14, -8.76, 'c');
    char xxx[6];
    strcpy(xxx, month);
    printf("%s\n", xxx);
    abc();
    int a;
//    scanf("%d", &a);
//    printf("%d", a);
    char in_s[100];
    scanf("%s", in_s);
    printf("%s", in_s);
}
