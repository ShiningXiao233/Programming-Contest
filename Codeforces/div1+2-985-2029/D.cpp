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

set<int> G[N];
vector<tuple<int, int, int> > ans;
void in_pass(int a, int b) {
    if (G[a].find(b) == G[a].end()) {
        G[a].insert(b);
        G[b].insert(a);
    } else {
        G[a].erase(b);
        G[b].erase(a);
    }
}

void pass(int a, int b, int c) {
    in_pass(a, b);
    in_pass(c, b);
    in_pass(a, c);
    ans.push_back(make_tuple(a, b, c));
}

int n, m;


void sol() {
    cin >> n >> m;
    int u, v;
    ans.clear();
    // for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }    
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        if (G[i].size() >= 2) {
            vector<int> s;
            int a = i;
            for (int v : G[i]) s.push_back(v);
            for (int i = 0; i < s.size(); i += 2) {
                if (i == s.size() - 1) continue;
                pass(a, s[i], s[i + 1]);
            }    
        }
        if (G[i].size() == 0) tmp.push_back(i);
    }
    // cout << tmp.size() << endl;
    if (tmp.size() != n) {
        int a = 0, b;
        for (int i = 1; i <= n; ++i) {
            if (G[i].size()) {
                a = i;

                b = *G[i].begin();
                G[i].erase(b);
                G[b].erase(a);
                for (int v : tmp) {
                    ans.push_back(make_tuple(a, b, v));
                    b = v;
                }
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (G[i].size()) {
                int c = i;
                int d = *G[i].begin();
                G[c].erase(d);
                G[d].erase(c);
                ans.push_back(make_tuple(a, c, d));
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto [a, b, c] : ans) {
        cout << a << ' ' << b << ' ' << c << '\n';
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // break;
    }
}