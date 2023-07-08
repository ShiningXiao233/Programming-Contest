#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5+100;
int a[N], n;
int f[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        f[i] += f[i - 1];
        if (i & 1) {
            f[i] += a[i] - a[i - 1];
        }
    }
    int q, l, r;
    int x, y, ans = 0;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        x = lower_bound(a + 1, a + n + 1, l) - a;
        y = upper_bound(a + 1, a + n + 1, r) - a - 1;
        ans = 0;
        if (x <= y) {
            ans = f[y] - f[x];
            if (x & 1) {
                ans += a[x] - l;
            }
            if (!(y & 1)) {
                ans += r - a[y];
            }
        } else {
            if (x & 1) {
                ans = r - l;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}