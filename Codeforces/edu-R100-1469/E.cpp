#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e6 + 100;
const int MOD = 998244353;
using ll = long long;

int to[N * 22][2];
bool is_ok[N * 22];
int a[N];
int dep;
int idx;

void dfs(int id, int cnt, vector<char*>& g) {
    to[id][0] = to[id][1] = 0;
    is_ok[id] = false;
    if (g.size() == 0) { 
        is_ok[id] = true;
        return; 
    }
    if (cnt == 0) return;
    vector<char*> a0, a1;
    for (auto ptr : g) {
        if (*ptr == '0') a1.push_back(ptr + 1);
        else a0.push_back(ptr + 1);
    }
    to[id][0] = ++idx;
    to[id][1] = ++idx;
    dfs(to[id][0], cnt - 1, a0);
    dfs(to[id][1], cnt - 1, a1);
    is_ok[id] = is_ok[to[id][1]] | is_ok[to[id][0]]; 
}

void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;    
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '0') a[i] = a[i - 1];
        else a[i] = a[i - 1] + 1;
    }
    string ans("");
    int len = max(0, k - 20);
    // cout << len << endl;
    vector<char*> g;
    for (int i = 1; i <= n - k + 1; ++i) {
        if (s[i + len - 1] - s[i - 1] == len) {
            g.push_back(&s[i + len - 1]);
        }
    }
    // for (auto x : g) {
    //     int xx = k;
    //     while (xx --) {
    //         cout << (*x++);
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < len; ++i) {
        ans += '0';
    }
    dep = k - len;
    idx = 1;

    dfs(1, dep, g);
    int p = 1;
    if (!is_ok[p]) {
        cout <<"NO\n";
        return;
    }
    // for (int i = 1; i <= idx; ++i) {
    //     cout << i << ' ' << to[i][0] << ' ' << to[i][1] << ' ' << is_ok[i] << endl;
    // }
    cout << "YES\n";
    is_ok[0] = true;
    // cout << p << endl;
    for (int i = 1; i <= dep; ++i) {
        if (is_ok[to[p][0]]) {
            ans += '0';
            p = to[p][0];
        } else {
            ans += '1';
            p = to[p][1];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}