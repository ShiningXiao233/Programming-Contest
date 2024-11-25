#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cstring>
using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;

int n;

vector<int> pos[20];

int dp[1 << 20];

void sol() {
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        a --;
        pos[a].push_back(i);
    }  
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = -1;

    int st = (1 << 20), x, ans = 0;
    for (int i = 0; i < st; ++i) {
        if (dp[i] > n) continue;
        int cnt = 0;
        for (int j = 0; j < 20; ++j) {
            if ((i >> j) & 1) {cnt ++; continue;}
            auto it = upper_bound(pos[j].begin(), pos[j].end(), dp[i]);
            if (it == pos[j].end() || (it + 1) == pos[j].end()) continue;
            it ++;
            x = i | (1 << j);
            dp[x] = min(dp[x], *it);
        }
        ans = max(ans, cnt * 2);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
}