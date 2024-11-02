#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;

void sol() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[j][i];
            if (i) a[j][i] |= a[j][i - 1];
        }
    }
    int m;
    int R, v, x;
    char opt;
    while (q --) {
        cin >> m;
        int l = 0, r = n - 1;
        while (m --) {
            cin >> R >> opt >> v;
            R -= 1;
            if (opt == '>') {
                x = upper_bound(a[R].begin(), a[R].end(), v) - a[R].begin();
                l = max(l, x);
            } else {
                x = lower_bound(a[R].begin(), a[R].end(), v) - a[R].begin() - 1;
                r = min(x, r);
            }
            // cout << l << ' ' << r << '\n';
        }
        cout << (l <= r ? l + 1 : -1) << '\n';
        // return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
}