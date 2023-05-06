#include <cstdio>

int func1 (int x);

using namespace std;

int main() {
	int x = 1;
	// printf("i am %d", x);
	func1(1);
	printf("%p\n", &x);
	int *ptr = &x;
	printf("%p", ptr);
	printf("%d", *ptr);
	return 0;
}

int func1 (int x) {
	return x;
}