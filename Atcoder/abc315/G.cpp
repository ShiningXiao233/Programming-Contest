#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
ll n, a, b, c, x;
ll res = 0;

void exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0ll) {
        x = 1ll;
        y = 0ll;
        return;
    }
    exgcd(b, a % b, x, y);
    ll tx = x, ty = y;
    x = ty;
    y = tx  - (a / b) * ty;
}

ll get_ans(ll a, ll b, ll c) {
    if (c <= 0) return 0;
    ll gg = __gcd(a, b);
    a /= gg;
    b /= gg;
    if (c % gg > 0) return 0;
    c /= gg;
    ll tx, ty;
    exgcd(a, b, tx, ty);
    ll maxn = min(n, (c - b) / a);
    ll minn = max(0ll, (c - n * b - 1) / a);
    ll x = c % b * tx % b;
    while (x <= 0) x += b;
    if (maxn < x) return 0;
    if (maxn <= minn) return 0;
    ll r = (maxn - x) / b + 1;
    ll l;
    if (minn < x) l = 0;
    else l = (minn - x) / b + 1;

    return r - l;
    
}

void sol() {
    cin >> n >> a >> b >> c >> x;
    for (int i = 1; i <= n; ++i) {
        res += get_ans(a, b, x - c * i);
    }
    cout << res << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}