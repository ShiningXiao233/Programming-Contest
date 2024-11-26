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

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> G(1000002, 1000000000);
    for (int i = 0; i < n; ++i) {
        G[a[i]] = min(G[a[i]], a[i] - b[i]);
    }
    vector<int> ans(1000002, 0);
    int p = 1000000000;
    for (int i = 1; i <= 1000000; ++i) {
        p = min(p, G[i]);
        if (p <= i) ans[i] = ans[i - p] + 2;
        ans[i] = max(ans[i], ans[i - 1]);
    }
    ll anst = 0;
    while (m --) {
        int x;
        cin >> x;
        if (x <= 1000000) {
            // cout << ans[x] << '\n';
            anst += ans[x];
        } else {
            int tmp = (x - 1000000 - 1) / p + 1;
            x -= tmp * p;
            anst += ans[x] + tmp * 2;
            // cout << ans[x] + tmp * 2 << '\n';
        }
    }
    cout << anst << '\n';
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
}