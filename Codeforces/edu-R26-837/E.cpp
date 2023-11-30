#include <iostream>

using namespace std;

typedef long long ll;

#include <vector>

vector<int> prime;
const int N = 1e6+10;
bool np[N];

#include <algorithm>

ll f(ll x, ll y) {
    if (y == 0ll) return 0;
    if (x == y) return 1;
    ll g = __gcd(x, y);
    x /= g;
    y /= g;
    if (x == 1ll) return y;
    ll t = x;
    ll gg = 1e18;
    for (int x : prime) {
        if (x * x > t) {
            break;
        }
        if (t % x == 0) {
            gg = min(gg, y % x);
            while (t % x == 0) t /= x;
        }
    }
    if (t > 1) {
        gg = min(gg, y % t);
    }
    return gg + f(x, y - gg);
}

int main() {
    for (int i = 2; i < N; ++i) {
        if (!np[i]) prime.push_back(i);
        for (int j = i + i; j < N; j += i) np[i] = true;
    }    
    ll x, y;
    cin >> x >> y;
    cout << f(x, y) << endl;
    return 0;
}