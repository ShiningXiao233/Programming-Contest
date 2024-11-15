#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const int N = 5e5 + 100;
const int MOD = 998244353;

int Max[N], f[N], ans[N], a[N];
int n;
#include <cmath>

#define lowbit(x) ((x) & (-x))

int get(int pos) {
    int res = 0;
    while (pos > 0) {
        res = max(res, f[pos]);
        pos -= lowbit(pos);
    }
    return res;
}

void upd(int x, int p) {
    while (x <= n) {
        f[x] = max(f[x], p);
        x += lowbit(x);
    }
}


void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> Max[i];
        a[i] = Max[i];
        Max[i] = max(Max[i], Max[i - 1]);
        f[i] = 0;
    }
    for (int i = n; i > 0; --i) {
        ans[i] = max(Max[i], get(Max[i] - 1));
        upd(a[i], ans[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}