#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int n, m, x;

void dfs(vector<int> &x, int id, int tmp, vector<int> &g) {
    if (id == x.size()) {
        g.push_back(tmp);
        return;
    }
    dfs(x, id + 1, (tmp + x[id]) % m, g);
    dfs(x, id + 1, tmp, g);
}

void sol() {
    
    cin >> n >> m;
    vector<int> a(n / 2), b;
    for (int i = 0; i < n / 2; ++i) {
        cin >> a[i];
    }
    for (int i = n / 2; i < n; ++i) {
        cin >> x;
        b.push_back(x);
    }
    vector<int> p1, p2;
    dfs(a, 0, 0, p1);
    dfs(b, 0, 0, p2);
    sort(p2.begin(), p2.end());
    int ans = 0;
    for (int v : p1) {
        int zz = upper_bound(p2.begin(), p2.end(), m - v - 1) - p2.begin() - 1;
        int zx = p2.size() - 1;
        if (zz >= 0) ans = max(ans, v + p2[zz]);
        if (zx >= 0) ans = max(ans, (v + p2[zx]) % m);
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