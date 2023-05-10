#include <iostream>

using namespace std;


void print_v(vector<int> &v1) {
	int len = v1.size();
	cout << len;
}

int main() {
	vector<int> v1 = {3,8,9,7,6};
	print_v(v1);
	return 0;
}















