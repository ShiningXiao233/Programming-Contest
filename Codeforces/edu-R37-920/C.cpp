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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << ' ';

    // }
    string x;
    cin >> x;

    int i = 0;
    while (i < n) {
        int r = i;
        while (r < n - 1 && x[r] == '1') ++r;
        // cout << i << ' ' << r << '\n';
        sort(a.begin() + i, a.begin() + r + 1);
        i = r + 1;
    }
    // for (int v : a) {
    //     cout << v << ' ';
    // }
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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