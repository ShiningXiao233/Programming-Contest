#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
const int MOD = 998244353;
using Pair = pair<int, int>;

using Pairl = pair<ll, int>;

vector<Pair> G[N];

int n, m;

ll dis[N << 2];

void sol() {    
    cin >> n >> m;
    int u, v, w;
    while (m --) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    priority_queue<Pairl, vector<Pairl>, greater<Pairl> > q;

    memset(dis, 0x3f, sizeof(dis));

    dis[1 << 2] = 0;
    q.push(make_pair(0, 1 << 2));

    while (!q.empty()) {
        auto u = q.top(); q.pop();
        if (dis[u.second] != u.first) continue;
        int uid = u.second >> 2, a = u.second & 1, b = (u.second >> 1) & 1;
        int tmp = 0, tmpv;
        for (auto [v, w] : G[v]) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    tmp = w;
                    if (i && a == 0) tmp -= w;
                    if (j && b == 0) tmp += w;
                    tmpv = v | i & (b << 1);
                    if (dis[tmpv] > dis[u.second] + tmp) {
                        dis[tmpv] = dis[u.second] + tmp;
                        q.push(make_pair(dis[tmpv], tmpv));
                    }
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dis[(i << 2) | 3] << ' ';
    }

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