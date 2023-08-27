#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int c[12][12];
int ans = 0;
int n, m;

int dp[12][1 << 11];

void sol() {
    memset(c, -0x3f, sizeof(c));
    cin >> n >> m;
    int a, b, x;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> x;
        a --;
        b --;
        c[a][b] = c[b][a] = max(c[a][b], x); 
    }    
    memset(dp, -0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i) dp[i][1 << i] = 0;
    int res = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            res = max(res, dp[j][i]);
            if (dp[j][i] >= 0)
            for (int k = 0; k < n; ++k) {
                if (j != k && ((i >> k) & 1) == 0) {
                    dp[k][i | (1 << k)] = max(
                        dp[k][i | (1 << k)],
                        c[j][k] + dp[j][i]
                    );
                }
            }
        }
    }
    cout << res << '\n';
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