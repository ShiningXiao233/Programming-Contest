#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2003 + 100;
const int MOD = 998244353;
ll X[N], L[N];
int n;
pair<ll, ll> tmp[N];

int chk_k(ll k) {
    for (int i = 1; i <= n; ++i) {
        tmp[i] = {abs(k - X[i]), X[i] - k};
    }
    sort(tmp + 1, tmp + n + 1);
    int tr = 0, tl = 0;
    for (int i = 1; i <= n; ++i) {
        if (tmp[i].first <= L[i]) continue;
        if (tmp[i].second < 0) tl = 1;
        if (tmp[i].second > 0) tr = 1;
    }
    if (tl == 1 && tr == 0) return -1;
    if (tl == 0 && tr == 1) return 1;
    if (tl == 1 && tr == 1) return 2;
    return 0;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i];
    }    
    for (int i = 1; i <= n; ++i) {
        cin >> L[i];
    }
    ll tans = 0;
    X[0] = X[1] - L[1];
    X[n + 1] = X[n] + L[1] + 1;
    for (int i = 1; i <= n + 1; ++i) {
        ll l, r, mid, ansl = 2e18 + 1, ansr = -2e18 - 1;
        l = X[i - 1];
        r = X[i] - 1;
        // cout << l << ' ' << r << endl;
        while (l <= r) {
            mid = (l + r) >> 1;
            int p = chk_k(mid);
            // cout << " +++ " << mid << ' ' << p << endl;
            if (p == 0) {
                r = mid - 1;
                ansl = mid;
            } else if (p == -1) {
                r = mid - 1;
            } else if (p == 1) {
                l = mid + 1;
            } else {
                ansl = 2e18 + 1;
                break;
            }
        }
        l = X[i - 1];
        r = X[i] - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            int p = chk_k(mid);
            if (p == 0) {
                l = mid + 1;
                ansr = mid;
            } else if (p == -1) {
                r = mid - 1;
            } else if (p == 1) {
                l = mid + 1;
            } else {
                ansr = -2e18 - 1;
                break;
            }
        }
        // cout << " --- " << ansl << ' ' << ansr << endl;
        if (ansr >= ansl) {
            tans += ansr - ansl + 1;
        }
    }
    // cout << chk_k(-2) << endl;
    cout << tans << endl;
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