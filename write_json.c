#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Player {
	char name[1000];
};

int main() {
	struct Player p1;
	char x[20];
	strcpy(x, "i am ok");
	printf("%s", x);
	strcpy(p1.name, "Brian leung");
	printf("%s", p1.name);
	return 0;
}