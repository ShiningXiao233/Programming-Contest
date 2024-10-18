#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <list>

using namespace std;

const int N = 3e5 + 100;
const int MOD = 998244353;
using ll = long long;
int q[N];

int f[N], cc[N];
list<int> ss[N];
int k, n;

int get_f(int x) {
    return x == f[x] ? x : f[x] = get_f(f[x]);
}

vector<int> G[N];
int d[N];

void sol() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> q[i], f[i] = i, ss[i].push_back(i);
    while (k --) {
        int a, b;
        cin >> a >> b;
        int aa = get_f(a);
        int bb = get_f(b);
        if (aa == bb || a != ss[aa].back() || b != ss[bb].front()) {
            cout << 0 << endl;
            return;
        }
        ss[aa].splice(ss[aa].end(), ss[bb]);
        f[bb] = aa;
    }
    for (int i = 1; i <= n; ++i) {
        if (cc[i]) continue;
        int a = get_f(i);
        int cnt = 0;
        // cout << i << " : ";
        for (int v : ss[a]) {
            cc[v] = ++cnt;
            // cout << v << ' ';
        }
        // cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        int a = q[i], b = i;
        if (a != 0) {
            a = get_f(a);
            b = get_f(b);
            if (a == b) {
                if (cc[q[i]] > cc[i]) {
                    cout << 0 << endl;
                    return;
                }
            } else {
                G[a].push_back(b);
                d[b] ++;
            }
        }
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0 && f[i] == i) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : ss[u]) {
            ans.push_back(v);
        }
        for (int v : G[u]) {
            d[v] --;
            if (d[v] == 0) q.push(v);
        }
    }
    if (ans.size() != n) {
        cout << 0 << endl;
        return;
    }
    // cout << ans.size() << endl;
    for (int v : ans) {
        cout << v << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
}