#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
const int N = 1e6 + 100;
const int MOD = 998244353;

int a[200];
vector<int> sp;
int xx[N];
int f[N];

#define lowbit(x) ((x) & -(x))

void upd(int pos, int val) {
    while (pos < N) {
        f[pos] += val;
        pos += lowbit(pos);
    }
}

int get(int pos) {
    int res = 0;
    while (pos > 0) {
        res += f[pos];
        pos -= lowbit(pos);
    }
    return res;
}

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) {
        cin >> xx[i];
        sp.push_back(xx[i]);
    }
    sp.push_back(0);
    sort(sp.begin(), sp.end());
    sp.erase(unique(sp.begin(), sp.end()), sp.end());
    for (int i = 0; i < sp.size(); ++i) {
        xx[i] = lower_bound(sp.begin(), sp.end(), xx[i]) - sp.begin();
    }

    ll ans = 1ll * n * (n - 1) / 2 * m * (m + 1) / 2;
    int op = 0;
    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= m; ++j) {
            a[j] = xx[++op];
            ans += get(N - 1) - get(a[j]);
        }
        for (int j = 1; j <= m; ++j) {
            upd(a[j], 1);
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
    exit(0);
}