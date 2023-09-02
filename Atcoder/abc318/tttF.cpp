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

void get_k(ll k, ll &lt, ll &rt) {
    rt = 2e18;
    lt = 2e18;

    for (int i = 1; i <= n; ++i) {
        lt = min(X[i] - (k - L[i]), lt);
        rt = min((k + L[i]) - X[i], rt);
    }
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i];
    }    
    for (int i = 1; i <= n; ++i) {
        cin >> L[i];
    }
    ll l = X[1] - L[1] - 1, r = X[n] + L[n] + 1, mid, ansl = 2e18, ansr = -2e18;
    ll tmpl, tmpr;
    while (l <= r) {
        mid = (l + r) >> 1;
        get_k(mid, tmpl, tmpr);
        if (tmpl >= 0 && tmpr >= 0) {
            r = mid - 1;
            ansl = mid;
        } else if (tmpl >= 0 && tmpr < 0) {
            l = mid + 1;
        } else if (tmpl < 0 && tmpr >= 0) {
            r = mid - 1;
        } else {
            cout << 0 << endl;
            exit(0);
        }
    }
    l = -1e18 - 1; r = 1e18 + 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        get_k(mid, tmpl, tmpr);
        if (tmpl >= 0 && tmpr >= 0) {
            l = mid + 1;
            ansr = mid;
        } else if (tmpl >= 0 && tmpr < 0) {
            l = mid + 1;
        } else if (tmpl < 0 && tmpr >= 0) {
            r = mid - 1;
        } else {
            cout << 0 << endl;
            exit(0);
        }
    }
    if (ansl <= ansr) {
        cout << ansr - ansl + 1 << endl;
    } else {
        cout << 0 << endl;
    }
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