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

vector<int> G[N];
int n;

int dfs(int u) {
    int res = 1;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int v : G[u]) {
        q.push(dfs(v));    
    }
    while (q.size() > 2) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        // if (u == 1) {
        //     cout << " -- " << b + 1 << '\n';
        // }
        q.push(b + 1);
    }
    // if (u == 1) {
    //     cout << "=" << q.size() << endl;
    // }
    while (!q.empty()) {
        // cout << "+= " << q.top() << endl;

        res = q.top() + 1;
        q.pop();
    }
    // cout << u << ' ' << res << '\n';
    return res;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        G[x].push_back(i);
    }
    cout << dfs(1) - 1 << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}