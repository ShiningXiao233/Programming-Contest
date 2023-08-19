#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
const int MOD = 998244353;

vector<int> G[N];
int n, vis[N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
    if (u != 1) {
        cout << u << ' ';
    }
}

void sol() {
    cin >> n;
    int x, c;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            cin >> c;
            G[i].push_back(c);
        }
    }    
    dfs(1);
    
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