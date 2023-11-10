#include <iostream>

using namespace std;

int n, m;

#include <vector>
const int N = 1e6+100;
vector<int> G[N];

int Mi[N];

void dfs(int u, int mm, int fa) {
    Mi[u] = min(mm, u);
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs(v, Mi[u], u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int v, u;
    for (int i = 1; i < n; ++i) {
        cin >> v >> u;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int opt, w;
    
    cin >> opt >> w;
    w = w % n + 1;
    dfs(w, w, 0);
    int S = w, last = 0;
    // cout << "S"  << ' ' << S << endl;
    while (-- m) {
        cin >> opt >> w;
        w = (w + last) % n + 1;
        // cout << opt << ' ' << w << endl;
        if (opt == 1) {
            Mi[S] = min(Mi[S], Mi[w]);
        } else {
            cout << (last = min(Mi[S], Mi[w])) << '\n';
        }
    }
    return 0;
}