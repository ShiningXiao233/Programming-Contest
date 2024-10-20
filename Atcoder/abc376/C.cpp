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
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<bool> pre_a(n, false), suf_a(n, false);
    int i = 0;
    while (i < n - 1 && a[i] <= b[i]) pre_a[i ++] = true;
    // cout << i << endl;
    i = n - 1;
    while (i > 0 && a[i] <= b[i - 1]) suf_a[-- i] = true;
    // cout << i << endl;
    int ans = -1;
    if (suf_a[0]) ans = a[0];
    else {
        for (int i = 1; i < n - 1; ++i) {
            if (pre_a[i - 1] && suf_a[i]) {
                ans = a[i];
                break;
            }
        }
        if (ans == -1 && pre_a[n - 2]) ans = a[n - 1];
    }
    cout << ans << endl;
    
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
}