#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 3e5 + 100;
const int MOD = 998244353;
int n, m;

vector<int> G[N];
int ans = 0;
int dis[N];

void dfs(int x, int g) {
    dis[x] = max(dis[x], g);
    if (dis[x] > 0) ans ++;
    for (int v : G[x]) {
        dfs(v, dis[x] - 1);
    }
}

void sol() {
    cin >> n >> m;
    int p;
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        G[p].push_back(i);
    }
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        dis[x] = max(dis[x], y + 1);
    }
    dfs(1, 0);
    cout << ans << '\n';
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