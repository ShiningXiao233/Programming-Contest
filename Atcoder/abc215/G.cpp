#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 998244353;

int qp(int x, int q = MOD - 2) {
    int res = 1;
    while (q) {
        if (q & 1) res = 1ll * res * x % MOD;
        q >>= 1;
        x = 1ll * x * x % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int c;
    map<int, int> mp, tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        mp[c] ++;
    }
    int m = mp.size();
    for (auto [x, y] : mp) {
        tmp[y] ++;
        
    }
    using Pair = pair<int, int>;
    vector<Pair> a(tmp.size());
    int idx = 0;
    for (auto [x, y] : tmp) {
        a[idx ++] = make_pair(x, y);
    }
    vector<int> f(n + 1), rf(n + 1);
    f[0] = rf[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = 1ll * f[i - 1] * i % MOD, rf[i] = qp(f[i]);

    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        ans = 0;

        for (int i = 0; i < a.size(); ++i) {
            if (n - a[i].first - k < 0) continue;
            int t = 1ll * f[n - a[i].first] * rf[n] % MOD;
            ans += 1ll * t * rf[n - a[i].first - k] % MOD * a[i].second % MOD; 
            ans %= MOD;
        }
        ans = 1ll * ans * f[n - k] % MOD;
        ans = (m - ans + MOD) % MOD;
        cout << ans << '\n';
    }
    return 0;
}