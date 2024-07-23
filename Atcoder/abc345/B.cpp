#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n > 0) cout << (n + 9) / 10 << '\n';
    else {
        cout << n / 10 << endl;
    }
    return 0;
}