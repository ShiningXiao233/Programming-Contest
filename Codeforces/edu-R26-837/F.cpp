#include <iostream>

using namespace std;

typedef long long ll;
const ll INF = 1e18 + 99834;
int n;
ll k;
const int N = 2e5+1000;
ll a[N];

#include <cstring>

void push(ll c[5][5], ll a[5][5], ll b[5][5]) {
    ll tmp[5][5];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                if (a[i][k] == 0 || (INF - tmp[i][j]) / a[i][k] >= b[k][j]) {
                    tmp[i][j] += a[i][k] * b[k][j];
                } else {
                    tmp[i][j] = INF;
                }
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            c[i][j] = tmp[i][j];
        }
    }
}

void qp(ll q, ll a[5][5]) {
    for (int i = 1; i < 5; ++i) a[i][i] = 1;
    ll x[5][5];
    memset(x, 0, sizeof(x));
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j <= i; ++j) {
            x[j][i] = 1;
        }
    }
    
    while (q) {
        
        if (q & 1) push(a, a, x);
        q >>= 1;
        push(x, x, x);
    }
}

bool chk(ll x) {
    ll t[5][5];
    memset(t, 0, sizeof(t));
    qp(x, t);
    ll tmp = 0;
    for (int i = 1; i < 5; ++i) {
        if (a[i] == 0 || (INF - tmp) / a[i] >= t[i][4])
            tmp += a[i] * t[i][4];
        else tmp = INF;
    }
    return tmp >= k;
}

int main() {    
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int p = 1;
    while (a[p] == 0) ++p;
    n -= p - 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i + p - 1];
    }
    ll cnt = 0;
    if (n >= 4) {
        while (1) {
            for (int i = 1; i <= n; ++i) {
                if (a[i] >= k) {
                    cout << cnt << endl;
                    return 0;
                }
            }
            ++cnt;
            for (int i = 1; i <= n; ++i) {
                a[i] += a[i - 1];
            }
        }
    } else {
        for (int i = 4; i >= 1; --i) {
            if (n) a[i] = a[n --];
            else a[i] = 0;    
        }
        ll l = 0, r = 1e18+10, ans = r, mid;

        while (l < r) {
            mid = (l + r) >> 1;
            if (chk(mid)) {
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}