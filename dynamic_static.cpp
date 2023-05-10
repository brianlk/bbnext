#include <iostream>

using namespace std;

class class_1 {
    public:
        int id;
};

void dynamic_allo() {
    class_1* p = new class_1[100000000];
    class_1 my_o;
    my_o.id=10000000;
    p[0]=my_o;
    p[1]=my_o;
    delete []p;
    for (;;) {
    }
}

void static_allo() {
    class_1 p[100000000];
    class_1 my_o;
    my_o.id=10000000;
    p[0]=my_o;
    p[1]=my_o;
    for (;;) {
    }
}

int main() {
//    dynamic_allo();
    static_allo();
    return 0;
}
