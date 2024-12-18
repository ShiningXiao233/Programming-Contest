#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;
int n, k;
int dp[N][12];
int sum[N][12];

void sol() {
    cin >> n >> k;
    dp[0][0] = 1;
    sum[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
        
        for (int j = 2; j <= k; ++j) {
            dp[i][j] += dp[i - 1][j - 1];
            if (i == n && i >= 2)  dp[i][j] += sum[i - 2][j - 1];
            else if (i >= 3) dp[i][j] += sum[i - 3][j - 1];
            dp[i][j] %= MOD;
        }

        dp[i][k + 1] = (dp[i - 1][k] + dp[i - 1][k + 1]) % MOD;
        if (i == n && i >= 2) {
            dp[i][k + 1] += (sum[i - 2][k] + sum[i - 2][k + 1]) % MOD;
            dp[i][k + 1] %= MOD;
        }
        else if (i > 3) {
            dp[i][k + 1] += (sum[i - 3][k] + sum[i - 3][k + 1]) % MOD;
            dp[i][k + 1] %= MOD;
        }
        for (int j = 0; j <= k + 1; ++j) {
            sum[i][j] = (sum[i - 1][j] + dp[i][j]) % MOD;
        }
    }
    cout << (dp[n][k] + dp[n][k + 1]) % MOD << '\n';
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
}