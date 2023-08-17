#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2e5+100;
const int MOD = 998244353;

int dep[N];
bool visa[N], visb[N];
int n, m;
vector<int> G[N], rG[N];

void dfs(int u, int dpt, bool *vis, vector<int> *G, int *dep) {
    if (dep != NULL) dep[u] = dpt;
    vis[u] = 1;
    for (int v : G[u]) {
        if (!vis[v]) {
            dfs(v, dpt + 1, vis, G, dep);
        }
    }
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        rG[i].clear();
        visa[i] = visb[i] = 0;
        dep[i] = -1;
    }
    int u, v;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    dfs(1, 1, visa, rG, NULL);
    dfs(1, 1, visb, G, dep);
    int res = -1;
    for (int u = 1; u <= n; ++u) {
        if (visa[u] && visb[u])
            for (int v : G[u]) {
                if (visa[v] && visb[v]) {
                    if (res == -1) {
                        res = abs(dep[u] + 1 - dep[v]);
                    } else {
                        res = __gcd(res, abs(dep[u] + 1 - dep[v]));
                    }
                    
                }
            }
    }
    while (res % 5 == 0) res /= 5;
    while (res % 2 == 0) res /= 2;
    if (res == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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
    exit(0);
}