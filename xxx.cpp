#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <typeinfo>

int func1(int x);
void func2();
void func3();
void test_pass_ptr(int *x);
void test_loop();
void test_vector();
void test_type();
void test_input();
void convert_ascii();
void array_pointer();
void test_ref();

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
    test_type();
    convert_ascii();
    array_pointer();
    test_ref();
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
	int int_a[100] {1,2,3};
	int_a[9] = 1000;
//	for (;;) {
//	}
//  int ss = sizeof(int_a) / sizeof(int);
//  printf("Size of array %d\n", ss);
}

void test_vector() {
	vector<int> v1 = {1, 2};
	for (const int &i : v1) {
		printf("%d\n", i);
	}
}

void test_type(){
    char *x;
//    printf("%s", typeid(x).name());
//    printf("%p", x);
}

void convert_ascii(){
    char x = 'a';
    int y = (int)x;
    printf("%d\n", y);
}

void array_pointer(){
    char x[] = "abcdef";
    char *p_x = x;
    printf("%c\n", *p_x);
    printf("%p\n", x);
    char *next_x = p_x + 1;
    printf("%c\n", *next_x);
}

void pointer_array(){
    char *x[3];
    char a[2] = "1";
    char b[2] = "2";
    char c[2] = "3";
    x[0] = a;
    x[1] = b;
    x[2] = c;
}

void test_ref() {
    int x = 1;
    int &y = x;
    printf("%d %p\n", x, &x);
    printf("%d %p\n", y, &y);
}
