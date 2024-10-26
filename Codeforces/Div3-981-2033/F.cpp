#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
const int MOD = static_cast<int>(1e9 + 7);
using ll = long long;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a% b);
}

int G(ll n, int k) {
    // cout << n << ' ' << k << endl;
    if (k == 1) return n % MOD;
    int idx = 1;
    int f[2] = {1, 1};
    int tmp, pre = 0;
    while (f[0] != 0) {
        // cout << f[0] << " - " << f[1] << endl;
        tmp = f[0] + f[1];
        tmp = tmp >= k ? tmp - k : tmp;
        pre = f[0];
        f[0] = f[1];
        f[1] = tmp;
        idx ++;
    }
    if (n == 0) return idx;
    else {
        auto p = gcd(pre, k);
        if (p == 1) {
            return n % MOD * idx % MOD;
        }
        n -= 1;
        k /= p;
        return (idx + G(n - 1, k)) % MOD;
    }
}

void sol() {
    ll n;
    int k;
    cin >> n >> k;
    cout << G(n, k) << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}