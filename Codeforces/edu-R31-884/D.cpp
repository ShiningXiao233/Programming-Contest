#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        q.push(a);
    }
    if (!(n & 1)) q.push(0);
    while (q.size() > 1) {
        ll t1 = q.top(); q.pop();
        ll t2 = q.top(); q.pop();
        ll t3 = q.top(); q.pop();
        ans += t1 + t2 + t3;
        q.push(t1 + t2 + t3);
    }
    cout << ans << '\n';
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