#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 3e5 + 100;
const int MOD = 998244353;

int a[N], b[N];
int n, k;

ll chk(ll t) {
    ll g = 0;
        for (int  i = 1; i <= n; ++i) {
            if (a[i] >= t) g += b[i];
        }
    return g;
}

void sol() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    } 
    ll l = 1, r = 2e9, ans = -1;
    // cout << chk(2000000000) << '\n';
    while (l <= r) {
        ll mid = (l + r) >> 1;
        
        if (chk(mid) <= k) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
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
}