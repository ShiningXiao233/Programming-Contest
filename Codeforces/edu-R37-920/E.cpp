#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;
int d[N]; 
using Pair = pair<int, int>;
set<Pair> mp;
vector<int> G[N];
int f[N];

int idx = 0;

int get_fa(int x) {
    return f[x] == x ? x : (f[x] = get_fa(f[x]));
}

void sol() {
    int n, m;
    cin >> n >> m;
    while (m --) {
        int u, v;
        cin >> u >> v;
        d[u] ++;
        d[v] ++;
        mp.insert(make_pair(u, v));
        mp.insert(make_pair(v, u));
        G[u].push_back(v);
        G[v].push_back(u);

    }
    int x = 0; d[x] = n + 4;
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        if (d[i] < d[x]) {
            x = i;
        }
    }
    if (x == 0) {
        exit(4);
    }
    vector<int> tmp(0);
    int cntx = 0;
    for (int i = 1; i <= n; ++i) {
        if (mp.find(make_pair(i, x)) == mp.end()) {
            f[i] = x;
            cntx ++;
        } else {
            tmp.push_back(i);
        }
    }
    for (int v : tmp) {
        for (int u : tmp) {
            if (mp.find(make_pair(u, v)) != mp.end()) continue;
            int fv = get_fa(v);
            int fu = get_fa(u);
            if (fv != fu) {
                f[fv] = fu;

            }
        }
    }
    // cout << x << ": == " << cntx << '\n';
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << " : " << get_fa(i) << '\n';
    // }
    
    vector<bool> kpi(n + 1, false);

    for (int u : tmp) {
        // if (get_fa(u) == x) continue;
        int cnt = cntx;
        for (int v : G[u]) {
            if (get_fa(v) == x) {
                // cout << "-> " << v << ' ' << u << '\n';
                cnt --;
            }
        }
        // cout << u << ' ' << " == " << cnt << '\n';
        if (cnt > 0) {

            kpi[u] = true;
            // f[get_fa(u)] = x;
        }
    }
    for (int v : tmp) {
        if (kpi[v]) f[get_fa(v)] = x;
    }
    vector<int> pcnt(n);
    for (int i = 1; i <= n; ++i) {
        // if (kpi[i]) f[get_fa(i)] = x;
        get_fa(i);
        pcnt[f[i] - 1] ++;
    }
    sort(pcnt.begin(), pcnt.end());
    cout << pcnt.end() - upper_bound(pcnt.begin(), pcnt.end(), 0) << '\n';
    for (int v : pcnt) {
        if (v) {
            cout << v << ' ';
        }
    }
    cout << '\n';
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