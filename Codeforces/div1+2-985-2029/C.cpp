#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 3e5 + 100;
const int MOD = 998244353;
using ll = long long;
int a[N], s[N];
int n;

bool chk(int x) {
    int c = x;
    s[n + 1] = n + 100;
    for (int i = n; i >= 1; --i) {
        if (a[i] >= x) {
            s[i] = x - 1;
            --x;
        } else {
            s[i] = x + 1;
            ++x;
        }
        s[i] = min(s[i], s[i + 1]);
    }
    x = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i + 1] <= x) return 1;
        if (a[i] == x) continue;
        if (a[i] > x) ++x;
        else --x;
        if (x >= c) return 1;
    }
    return 0;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n + 1, ans = 0;
    while (l < r) {
        int mid = (l + r) / 2;
        if (chk(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << ans << '\n';
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
}