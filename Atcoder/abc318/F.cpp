#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2003 + 100;
const int MOD = 998244353;
ll X[N], L[N], tmp[N];
int n;
ll pos[N * N], cnt = 0;

bool chk(ll k) {
    for (int i = 1; i <= n; ++i) {
        tmp[i] = abs(k - X[i]);
    }
    sort(tmp + 1, tmp + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (tmp[i] > L[i]) return 0;
    }
    return 1;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i];
    }    
    for (int i = 1; i <= n; ++i) {
        cin >> L[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pos[++cnt] = X[i] + L[j];
            pos[++cnt] = X[i] - L[j] - 1;
        }
    }
    sort(pos + 1, pos + cnt + 1);
    ll tans = 0;
    for (int i = 2; i <= cnt; ++i) {
        if (chk(pos[i])) tans += pos[i] - pos[i - 1];
    }
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