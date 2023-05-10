#include <iostream>
#include <vector>

using namespace std;

void show_v(vector<int> v1);
void swap_once(vector<int> &vc, int index);


void show_v(vector<int> v1) {
	int len = v1.size();
	for (int i=0; i<len; i++) {
		cout << v1[i] <<endl;
	}
}

void swap_once(vector<int> &vc, int index) {
	int temp;
	int len = vc.size();
	// {3,8,9,7,6} -> {6,3,8,9,7}
	temp = vc[len-1];
	for(int i=len-1; i>index; i--) {
		vc[i] = vc[i-1];
	}
	vc[index] = temp;
	show_v(vc);
}

int main() {
	vector<int> v1 = {3,8,9,7,6}; // {6,7,9,8,3}
	// show_v(v1);
	swap_once(v1, 0);
	// show_v(v1);
	cout << "========================" << endl;
	swap_once(v1, 1);
	// show_v(v1);
	cout << "========================" << endl;
	swap_once(v1, 2);
	// show_v(v1);
	cout << "========================" << endl;
	swap_once(v1, 3);
	// show_v(v1);
	cout << "========================" << endl;
	// swap_once(v1, 4);
	// show_v(v1);

	return 0;
}