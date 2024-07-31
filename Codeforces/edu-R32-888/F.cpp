#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const int N = 506;
const int MOD = static_cast<int>(1e9 + 7);

int mp[N][N];
int dp[N][N][2]; // dp[i][j][0/1] i->j是否连接了边
int n;


void DP(int l, int r) {
    if (dp[l][r][0] != -1) return;
    if (l > r) {
        dp[l][r][0] = dp[l][r][1] = 0;
    }
    if (l == r) {
        dp[l][r][0] = 0;
        dp[l][r][1] = 1;
        return;
    }    
    dp[l][r][0] = dp[l][r][1] = 0;
    if (mp[l][r])
        for (int i = l; i < r; ++i) {
            DP(l, i);
            DP(i + 1, r);
            dp[l][r][1] += 1ll * (dp[l][i][1] +  + dp[l][i][0]) * (dp[i + 1][r][0] + dp[i + 1][r][1]) % MOD;
            dp[l][r][1] %= MOD;
            
        }
    for (int i = l + 1; i < r; ++i) {
        DP(l, i);
        DP(i, r);
        dp[l][r][0] += 1ll * (dp[l][i][1]) * (dp[i][r][0] + dp[i][r][1]) % MOD;
        // if (l == 0 && r == n - 1) {
        //     cout << (dp[l][i][1]) << " -- " << (dp[i][r][0] + dp[i][r][1]) << "\n";
        // }
        dp[l][r][0] %= MOD;
    }
    // if (!mp[l][r]) dp[l][r][1] = 0;
}

void sol() {
    memset(dp, -1, sizeof(dp));
    cin >> n;    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mp[i][j];
        }
        mp[i][i] = 1;
    }
    DP(0, n - 1);
    // cout << dp[0][n - 1][0] << ' ' << dp[0][n - 1][1] << '\n';
    cout << (dp[0][n - 1][0] + dp[0][n - 1][1]) % MOD << '\n';
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