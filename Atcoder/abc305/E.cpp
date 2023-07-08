#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+100;

int n, m, k;
vector<int> G[N];

int dis[N];
int vis[N];
priority_queue< pair<int, int> > q;

int main() {
    cin >> n >> m >> k;
    int u, v, ds;
    while (m--) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= k; ++i) {
        cin >> u >> v;
        vis[u] = 1;
        dis[u] = max(dis[u], v);
        q.push({dis[u], u});
    }
    while (!q.empty()) {
        ds = q.top().first;
        u = q.top().second; 
        q.pop();
        if (ds != dis[u]) continue;
        // cout << "===" << u << ' ' << ds << '\n';
        if (dis[u] > 0) {
            for (int v : G[u]) {
                if (dis[v] < dis[u] - 1) {
                    vis[v] = 1;
                    dis[v] = dis[u] - 1;
                    q.push({dis[v], v});
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
    return 0;
}