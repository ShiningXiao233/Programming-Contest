/*
割边
*/

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

int n, m;
using Pair = pair<int, int>;
vector<Pair> G[N];
int dfn[N], low[N], DFN = 0;
int Sz[N];
ll ans = 0;
void dfs(int u, int inedge) {
    // cout << u << '\n';
    dfn[u] = low[u] = ++DFN;
    Sz[u] = 1;
    for (auto [v, id] : G[u]) {
        if (!dfn[v]) {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            Sz[u] += Sz[v];
            if (low[v] > dfn[u]) {
                ans = max<ll>(ans, 1ll * Sz[v] * (n - Sz[v]));
                // cout << u << ' ' << Sz[v] << ' ' << v << endl;
            }
        } else if (id != inedge) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        dfn[i] = 0;
    }
    ans = 0;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(make_pair(b, i));
        G[b].push_back(make_pair(a, i));
    }
    DFN = 0;
    dfs(1, 0);
    cout << 1ll * n * (n - 1) / 2 - ans << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // break;
    }
}