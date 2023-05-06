#include <cstdio>
#include <vector>

int func1(int x);
void func2();

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
	return 0;
}

int func1(int x) {

	return x;
}

void func2() {
	Memory mem_oj;
	mem_oj.check_memory();
}