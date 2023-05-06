#include <cstdio>
#include <vector>

int func1(int x);
void func2();
void func3();
void func4(int *x);

using namespace std;

class Memory {
	public:
		int memory_size;

		void check_memory() {
			printf("check memory.");
		}
};

int main() {
	vector<int> v1 = {1, 2};
	for (const int &i : v1) {
		printf("%d\n", i);
	}
	func2();
	func3();
	int x = 100;
	func4(&x);
	printf("x = %d", x);
	return 0;
}

int func1(int x) {

	return x;
}

void func2() {
	Memory mem_oj;
	mem_oj.check_memory();
	// printf("%c", 0x80);
}

void func3() {
	int a = 1000;
	int *a_ptr = &a;
	printf("%d\n", a);
	*a_ptr = 20000;
	printf("%d\n", *a_ptr);
	printf("a is %d\n", a);
}

void func4(int *x) {
	int *x_ptr = x;
	printf("%p", x_ptr);
	*x_ptr = 200;
}