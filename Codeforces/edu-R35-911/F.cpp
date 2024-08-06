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

int n;
vector<int> G[N];
int dep1[N], dep2[N];

void dfs(int u, int f, int *dep) {
    dep[u] = dep[f] + 1;
    for (int v : G[u]) {
        if (v == f) continue;
        dfs(v, u, dep);
    }
}

vector<int> gg;
#include <tuple>

vector<tuple<int, int, int>> ans;

int Maxlen = 0;
int Node1 = 0, Node2 = 0;
ll ansl = 0;
void dfs_ans(int u, int f) {
    if (dep1[u] + dep2[u] == Maxlen) {
        gg.push_back(u);
    }

    for (int v : G[u]) {
        if (v == f) continue;
        dfs_ans(v, u);
    }

    if (dep1[u] + dep2[u] != Maxlen) {
        if (dep1[u] > dep2[u]) {
            ans.push_back(make_tuple(Node1, u, u));
            ansl += dep1[u]; 
        } else {
            ansl += dep2[u]; 
            ans.push_back(make_tuple(Node2, u, u));
        }
    }
}


void sol() {
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }    
    dep1[0] = dep2[0] = -1;
    dfs(1, 0, dep1);
    for (int i = 1; i <= n; ++i) {
        if (dep1[i] > dep1[Node1]) Node1 = i;
    }
    dfs(Node1, 0, dep1);
    for (int i = 1; i <= n; ++i) {
        if (dep1[i] > dep1[Node2]) Node2 = i;
    }
    Maxlen = dep1[Node2];
    dfs(Node2, 0, dep2);
    // cout << Node1 << ' ' << Node2 << '\n';
    dfs_ans(Node1, 0);
    int ss = gg.size() - 1;
    for (int v : gg) {
        if (ss == 0) break;
        ansl += ss;
        ss --;
        ans.push_back(make_tuple(v, gg.back(), v));
    }
    cout << ansl << '\n';
    for (auto a : ans) {
        cout << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << '\n';
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