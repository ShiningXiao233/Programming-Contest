#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <memory>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;

vector<int> G[N];
string s;
int fail[N];
int ans[N]; // 代表lcp为i时，能分的最大k

using setptr = unique_ptr<set<int>>;

setptr dfs(int u) {
    setptr st(new set<int>());
    st->insert(u);
    for (int v : G[u]) {
        auto f = dfs(v);
        if (f->size() > st->size()) swap(f, st);
        for (auto v : *f) {
            st->insert(v);
        }
    }
    int cnt = 1;
    int p = 2 * u;
    while (u) {
        auto x = st->lower_bound(p);
        if (x == st->end()) break;
        p = *x + u;
        cnt ++;
    }
    ans[cnt] = max(ans[cnt], u);
    return st;
}

void sol() {
    int n, l, r;
    cin >> n >> l >> r;
    cin >> s;
    for (int i = 0; i <= n + 1; ++i) G[i].clear(), ans[i] = 0;
    G[0].push_back(1);
    for (int j = 0, i = 2; i <= n; ++i) {
        while (j && s[i - 1] != s[j]) j = fail[j];
        if (s[i - 1] == s[j]) ++j;
        fail[i] = j;
        G[j].push_back(i); 
    }
    dfs(0);
    for (int i = n; i > 0; --i) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = l; i <= r; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // break;
    }
}