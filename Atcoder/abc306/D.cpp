#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 3e5+100;
const int MOD = 998244353;
int n;

void sol() {
    cin >> n;
    ll dp[2][2] = {0};
    int x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        dp[i & 1][0] = dp[(i ^ 1) & 1][0];
        dp[i & 1][1] = dp[(i ^ 1) & 1][1];
        if (x == 0) {
            dp[i & 1][0] = max(dp[i & 1][0], dp[i & 1][0] + y);
            dp[i & 1][0] = max(dp[i & 1][0], dp[i & 1][1] + y);
        } else {
            dp[i & 1][1] = max(dp[i & 1][0] + y, dp[i & 1][1]);
        }
    }
    cout << max(dp[n & 1][0], dp[n & 1][1]) << '\n';
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