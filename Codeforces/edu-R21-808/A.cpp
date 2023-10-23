#include <iostream>

using namespace std;

class sol {

public:
    sol() {

    }
    int get(int x) {
        int t = 1;
        for (int i = 0; i < 10; ++i) {
            for (int k = 1; k < 10; ++k) {
                if (k * t > x) return k * t - x;
            }
            t *= 10;
        }
        return -1;
    }
private:
    
};

int main() {
    int n;
    cin >> n;
    sol a;
    cout << a.get(n) << '\n';
    return 0;
}