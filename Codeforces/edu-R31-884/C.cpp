#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int p[N], cn[N];
int n;

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }    
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = p[i], pp = p[i], cnt = 0;
        if (t == -1) continue;
        do {
            cnt ++;
            int k = t;
            t = p[t];
            p[k] = -1;
        } while (t != pp);
        cn[i] = cnt;
        ans += 1ll * cnt * cnt;
        // cout << "+++ " << cnt << '\n';
    }
    // cout << ans << '\n';
    sort(cn + 1, cn + n + 1);
    if (n > 1) {
        ans -= 1ll * cn[n] * cn[n];
        // cout << ans << " ------- " << cn[n] << '\n';
        ans -= 1ll * cn[n - 1] * cn[n - 1];
        // cout << ans << " ------- " << cn[n - 1] << '\n';
        // cout << cn[n] << ' ' << cn[n - 1] << '\n';
        ans += 1ll * (cn[n] + cn[n - 1]) * (cn[n] + cn[n - 1]);
        // cout << " -- " << cn[n] + cn[n - 1] << '\n';
    }
    cout << ans << '\n';
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