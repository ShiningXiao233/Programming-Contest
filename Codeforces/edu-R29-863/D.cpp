#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

#include <tuple>

void sol() {
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    using tp = tuple<int, int, int>;
    vector<tp> qr;
    int opt, l, r;
    while (q--) {
        cin >> opt >> l >> r;
        qr.push_back(make_tuple(opt, l, r));
    }
    reverse(qr.begin(), qr.end());
    while (m --) {
        int d;
        cin >> d;
        for (auto [opt, l, r] : qr) {
            if (d < l || r < d) continue;
            if (opt == 1) {
                d --;
                if (d < l) d = r;
            } else {
                d = l + r - d;
            }
        }
        cout << a[d - 1] << ' ';
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