#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5+100;

int main() {
    int n;
    using Pair = pair<int, int>;
    cin >> n;
    vector<Pair> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<int> dp(a[a.size() - 1].first + 6, 0);
    dp[0] = 1;
    const int MOD = 998244353;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= a[i].first - a[i].second; ++j) {
            ans += dp[j];
            ans %= MOD;
        }
        for (int j = dp.size() - 1; j >= a[i].second; --j) {
            dp[j] += dp[j - a[i].second];
            dp[j] %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}