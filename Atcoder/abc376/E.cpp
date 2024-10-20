#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;

void sol() {
    int n, k;
    cin >> n >> k;
    using Pair = pair<int, int>;

    vector<Pair> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first;
    for (int i = 0; i < n; ++i) cin >> a[i].second;
    sort(a.begin(), a.end());
    priority_queue<int> q;
    ll sub = 0;
    for (int i = 0; i < k - 1; ++i) {
        q.push(a[i].second);
        sub += a[i].second;
    }
    ll ans = static_cast<ll>(2e18);
    for (int i = k - 1; i < n; ++i) {
        ans = min(ans, (sub + a[i].second) * a[i].first);
        if (!q.empty() && a[i].second < q.top()) {
            sub -= q.top();
            sub += a[i].second;
            q.pop();
            q.push(a[i].second);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // return 0;
    }
}