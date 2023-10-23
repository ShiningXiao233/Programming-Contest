#include <iostream>

using namespace std;

class aa {

public:
    int p;
    aa(int a) : p(a) {

    }
    ~aa() {
        cout << p << endl;
    }

};

int main() {
    aa *a = new aa(3), *b  = new aa(1);
    delete a, b;
    return 0;
}