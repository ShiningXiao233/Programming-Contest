#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
ll a[N], b[N];
int k[N];
vector<int> G[N];
int n;

ll dfs(int u) {
    for (int v : G[u]) {
        a[u] += dfs(v);
        if (a[u] < -1000000000000000000ll) 
            a[u] = -1000000000000000000ll;
    }
    a[u] -= b[u];
    if (u == 1) return 0;
    if (a[u] >= 0) {
        return a[u];
    }
    else {
        a[u] = -a[u];
        if (1000000000000000000ll / k[u] < a[u]) {
            return -1000000000000000000ll;
        }
        else return -a[u] * k[u];
    }
}

void sol() {
    cin >> n;    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    } 
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        
    }
    int x;
    for (int i = 2; i <= n; ++i) {
        cin >> x >> k[i];
        G[x].push_back(i);
    }
    dfs(1);
    if (a[1] >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
