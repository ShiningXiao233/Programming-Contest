#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;

inline ll get_l(ll x) {
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

ll get(ll x, ll i, ll k) {
    ll res = get_l(x);
    if (k > x) return res;
    ll xx = (x - k) / (1ll << i);
    if (xx % 2 == 0) res ^= k;
    xx = get_l(xx) << i;
    res ^= xx;
    return res;
}

void sol() {
    ll l, r, i, k;
    cin >> l >> r >> i >> k;
    cout << (get(r, i, k) ^ get(l - 1, i, k)) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}