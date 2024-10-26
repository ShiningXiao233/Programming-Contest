#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;
int n;
vector<int> G[N];
int f[N][20];
int ff[N][20];
int fMax[N], CM[N], dep[N];

int dfs(int u = 1, int f = 0) {
    int Max1 = 0, f1 = 0, Max2 = 0, f2 = 0;
    for (int v : G[u]) {
        if (v == f) continue;
        int tmp = dfs(v, u);
        if (tmp > Max1) {
            Max2 = Max1;
            f2 = f1;
            Max1 = tmp;
            f1 = v;
        } else if (tmp > Max2) {
            Max2 = tmp;
            f2 = v;
        }
    }
    // cout << u << ' ' << Max1 << ' ' << Max2 << '\n';
    for (int v : G[u]) {
        if (v == f) continue;
        if (f1 == v) fMax[v] = Max2;
        else fMax[v] = Max1;
    }
    CM[u] = Max1;
    return Max1 + 1;
}

void dfs2(int u = 1, int fa = 0, int dp = 0) {
    dep[u] = dp;
    f[u][0] = fMax[u] + 1;
    ff[u][0] = fa;
    for (int i = 1; i < 20; ++i) {
        f[u][i] = max(f[u][i - 1],
        f[ff[u][i - 1]][i - 1] + (1 << (i - 1)));
        ff[u][i] = ff[ff[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs2(v, u, dp + 1);
    }
}

int get_ans(int x, int p) {
    int res = max(CM[x], p);
    // cout << x << ' ' << p << '\n';
    int fx = x;
    for (int i = 19; i >= 0; --i) {
        if (p >> i & 1) {
            res = max(res, dep[x] - dep[fx] + f[fx][i]);
            fx = ff[fx][i];
            // cout << fx << '\n';
        }
    }
    return res;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) G[i].clear();
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }    
    dfs(1);
    dfs2(1);
    // cout << f[7][0] << '\n';
    int m, x, k;
    // cout << get_ans(2, 3) << endl;
    cin >> m;
    while (m --) {
        cin >> x >> k;
        cout << get_ans(x, min(k, dep[x])) << ' ';
    }
    cout << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // return 0;
    }
}