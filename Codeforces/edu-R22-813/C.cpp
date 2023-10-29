#include <iostream>
#include <vector>


using namespace std;
const int N = 2e5+100;


vector<int> G[N];
int fa[N], dep[N], Mdep[N];
int n, x;

int dfs(int u = 1, int f = 0, int dpt = 0) {
    int MaxDpt = dpt;
    fa[u] = f;
    dep[u] = dpt;
    for (int v : G[u]) {
        if (v == f) continue;
        int tp = dfs(v, u, dpt + 1);
        MaxDpt = max(MaxDpt, tp);
    }
    Mdep[u] = MaxDpt;
    return MaxDpt;
}

int main() {
    int u, v;
    cin >> n >> x;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs();
    int ans = Mdep[x];
    u = x;
    while (u > 1) {
        if (dep[u] <= dep[x] - dep[u]) {
            break;
        }
        ans = max(ans, Mdep[u]);
        u = fa[u];
    }
    cout << ans * 2 << endl;
    return 0;
}