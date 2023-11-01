#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll m = n / 2;
    m /= (k + 1);
    ll a = m, b = m * k;

    cout << a << ' ' << b << ' ' << n - a - b << endl; 
    return 0;
}