#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cstring>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;
int n, m, t0, t1, t2;

using Pair = pair<int, int>;
using Pairll = pair<ll, int>;

vector<Pair> G[N], G1[N];
ll dis1[N], dis2[N], dis3[N];

void dijkstra(int T0,const vector<int>& s, vector<Pair>* G, ll* dis) {
    memset(dis, 0x3f, sizeof(ll) * (n + 1));
    priority_queue<Pairll, vector<Pairll>, greater<Pairll> > q;
    for (int v : s) {
        if (T0 == -1)
            dis[v] = dis1[v];
        else dis[v] = T0;
        q.push(make_pair(dis[v], v));
    }
    while (!q.empty()) {
        ll w = q.top().first;
        int u = q.top().second;
        q.pop();
        if (dis[u] != w) continue;
        for (auto [v, c] : G[u]) {
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                q.push(make_pair(dis[v], v));
            }
        }
    }

}

bool chk(int T0) {
    dijkstra(T0, {1}, G, dis1);
    vector<int> s;
    s.push_back(1);
    for (int i = 2; i <= n; ++i) {
        if (dis1[i] <= t1) {
            s.push_back(i);
        }
    }
    dijkstra(-1, s, G1, dis2);
    for (int i = 1; i <= n; ++i) {
        if (dis3[i] + max(1ll * t2, dis2[i]) <= t0) {
            return true;
        }
    }
    return false;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        G1[i].clear();
    }
    cin >> t0 >> t1 >> t2;
    int u, v, l1, l2;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> l1 >> l2;
        G[u].push_back(make_pair(v, l1));
        G[v].push_back(make_pair(u, l1));
        G1[u].push_back(make_pair(v, l2));
        G1[v].push_back(make_pair(u, l2));
    }
    dijkstra(0, {n}, G, dis3);
    int l = 0, r = t0, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (chk(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}