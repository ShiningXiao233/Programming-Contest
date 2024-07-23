#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5+100;

using Pair = pair<int, int>;
int n, m, k;
vector<Pair> G[N];
vector<Pair> GG[N];

int vis[N];
vector<int> ans;
int cnt;
void dfs1(int x) {
    cnt ++;
    if (cnt / 2 * 2 >= k) return;
    vis[x] = 1;
    for (auto v : G[x]) {
        if (!vis[v.first]) {
            GG[x].push_back(v);
            dfs1(v.first);
            if (cnt / 2 * 2 >= k) return;
        }
    }
}

int toget(int u, int id = -1) {
    int sum = 0;
    for (auto v : GG[u]) {
        sum ^= toget(v.first, v.second);
    }
    if (sum == 0 && id != -1) {
        ans.push_back(id);
    }
    return (sum == 0);
}

int main() {

    cin >> n >> m >> k;
    if (k & 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt = 0;
            dfs1(i);
            if (cnt > 0) {
                toget(i);
                k -= cnt / 2 * 2;
            }
                
        }
        if (k == 0) break;
    }
    if (k > 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << ans.size() << '\n';
        for (int v : ans) {
            cout << v << ' ';
        }
    }
    return 0;
}