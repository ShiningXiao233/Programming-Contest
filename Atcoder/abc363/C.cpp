#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int n, k;
string c;
set<string> st;
int vis[20];

void dfs(string p) {
    if (p.length() == n) {
        // cout << p << endl;
        for (int i = 0; i <= p.length() - k; ++i) {
            auto tmp = p.substr(i, k);
            auto rtmp = tmp;
            reverse(rtmp.begin(), rtmp.end());
            if (tmp == rtmp) {
                return;
            }
            // cout << p << " " << i << " = " << tmp << ' ' << rtmp << '\n';
        }
        st.insert(p);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(p + c[i]);
            vis[i] = 0;
        }
    }
}

void sol() {
    cin >> n >> k;
    cin >> c;
    dfs("");
    // for (auto x : st) {
    //     cout << x << '\n';
    // }
    cout << st.size() << '\n';
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