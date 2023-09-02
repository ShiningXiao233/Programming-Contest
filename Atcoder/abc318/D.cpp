#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

struct edge {
    int u, v, x;
}s[N];
int op = 0;
int n;
ll ans[1 << 17];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            op ++;
            cin >> s[op].x;
            s[op].u = i - 1;
            s[op].v = j - 1;
        }
    }
    ll tans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        tans = max(tans, ans[i]);
        for (int j = 1; j <= op; ++j) {
            if (((i >> s[j].u) & 1) == 0 && 
                ((i >> s[j].v) & 1) == 0) {
                    int p = i | (1 << s[j].u) | (1 << s[j].v);
                    ans[p] = max(ans[p], ans[i] + s[j].x);
                    // cout << ans[p] << endl;
                }
        }
    }
    cout << tans << endl;
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