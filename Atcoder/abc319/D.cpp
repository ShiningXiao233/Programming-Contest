#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
const int MOD = 998244353;

int m, n;
int L[N];

int chk(ll W) {
    int cnt = 0;
    ll tmp = 0;
    for (int i = 1; i <= n; ++i) {
        if (tmp < L[i]) {
            ++cnt;
            tmp = W;
        }
        if (tmp < L[i]) return 1e9;
        tmp -= L[i];
        tmp--;
    }
    return cnt;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> L[i];
    }
    ll l = 1, r = 1e16, mid, ans = r;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (chk(mid) <= m) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;

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