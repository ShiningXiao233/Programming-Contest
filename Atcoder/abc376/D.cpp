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


void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n), rG(n);
    vector<int> dis(n, 2 * n), rdis(n, 2 * n);
    int a, b;
    while (m --) {
        cin >> a >> b;
        --a;
        --b;
        if (a == 0 && b == 0) {
            cout << 1 << endl;
            return;
        }
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    auto get_dis = [](vector<int>&dis, vector<vector<int>> &G) -> void {
        queue<int> q;
        q.push(0); dis[0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : G[u]) {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    };
    get_dis(dis, G);
    get_dis(rdis, rG);
    int ans = n * 100;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, dis[i] + rdis[i]);
    }
    if (ans < 2 * n) {
        
    } else {
        ans = -1;

    }
    cout <<ans<< endl;
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
}