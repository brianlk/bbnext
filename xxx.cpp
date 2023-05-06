#include <cstdio>
#include <vector>

int func1(int x);
void func2();
void func3();
void test_pass_ptr(int *x);
void test_loop();
void test_vector();

using namespace std;

class Memory {
	public:
		int memory_size;

		void check_memory() {
			printf("check memory.");
		}
};

int main() {
	func2();
	func3();
	int x = 100;
	test_pass_ptr(&x);
	printf("x = %d", x);
	test_loop();
	test_vector();
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

void test_pass_ptr(int *x) {
	int *x_ptr = x;
	printf("%p", x_ptr);
	*x_ptr = 200;
}

void test_loop() {
	int int_a[10] = {1,2,3};
	int_a[9] = 1000;
	for (int i=0; i<12; i++) {
		printf("%d\n", int_a[i]);
	}
	int ss = sizeof(int_a) / sizeof(int);
	printf("Size of array %d\n", ss);
}

void test_vector() {
	vector<int> v1 = {1, 2};
	for (const int &i : v1) {
		printf("%d\n", i);
	}
}