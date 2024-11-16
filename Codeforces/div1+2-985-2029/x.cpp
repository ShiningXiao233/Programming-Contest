#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
using ll = long long;
ll a[N], sum[N], dp[35][35];
int n;
int P = 0;
ll DP(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int L = P - l;
    int R = P + r;
    dp[l][r] = sum[R] - sum[L - 1];
    ll tmp = sum[R] - sum[L - 1];
    if (L > 1 && a[L - 1] > tmp) dp[l][r] = max(dp[l][r], DP(l + 1, r));
    if (R < n && a[R + 1] > tmp) dp[l][r] = max(dp[l][r], DP(l, r + 1));
    return dp[l][r];
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        memset(dp, -1, sizeof(dp));
        P = i;
        cout << DP(0, 0) << ' ';
    }
    cout << endl;
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