#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int c[80];
ll f[40];
void dfs(int l, int r, ll n) {
    if (l > r) return;
    int pp = r - l - 1;
    ll tf = f[(pp + 1) / 2];
    // cout << l << ' ' << r << ' ' << n << '\n';
    for (int i = (l == 1); i < 10; ++i) {
        c[l] = c[r] = i;
        if (n > tf) {
            n -= tf;
        } else {
            dfs(l + 1, r - 1, n);
            return;
        }
    }
}

void sol() {
    ll n;
    cin >> n;
    if (n <= 10) {
        cout << n - 1 << endl;
        return;
    }
    int len = -1;
    f[0] = 1;
    n -= 10;
    for (int i = 1; i <= 40; ++i) f[i] = f[i - 1] * 10;
    for (int i = 2; i <= 40; ++i) {
        ll tmp = 9;
        for (int k = 1; k <= (i - 1) / 2; ++k) {
            tmp *= 10;
        }
        if (n > tmp) n -= tmp;
        else {
            len = i;
            break;
        }
    }
    // cout << len << ' ' << n << " === " << endl;
    dfs(1, len, n);
    for (int i = 1; i <= len; ++i) {
        cout << c[i];
    }
    cout << '\n';
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