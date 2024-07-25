#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n, x;
    cin >> n >> x;
    int res = 0, p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        res += p + (i > 0);
    }
    cout << ((res == x) ? "YES" : "NO") << '\n';
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