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
    int n, c;
    cin >> n >> c;
    int ans = 1;
    int x, p;
    cin >> p;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (x - p >= c) ans ++, p = x;
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