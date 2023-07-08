#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
const int N = 3e5 + 100;
const int MOD = 998244353;

vector<int> G[N];
int n1, n2, m;
int dis[N];

void bfs(int s) {
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }    
}

void sol() {
    int a, b;
    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }    
    memset(dis, 0x3f, sizeof(dis));
    bfs(1);
    bfs(n1 + n2);
    a = 0, b = 0;
    for (int i = 1; i <= n1; ++i) a = max(a, dis[i]);
    for (int i = n1 + 1; i <= n1 + n2; ++i) b = max(b, dis[i]);
    cout << a + b + 1 << '\n';
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