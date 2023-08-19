#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 3e5+100;
const int MOD = 998244353;
int n;

int ff1[N], ff2[N];

void sol() {
    cin >> n;
    int f, s;
    for (int i = 1; i <= n; ++i) {
        cin >> f >> s;
        if (s > ff1[f]) {
            ff2[f] = ff1[f];
            ff1[f] = s;
        } else if (s > ff2[f]) {
            ff2[f] = s;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, ff1[i] + ff2[i] / 2);
    }
    sort(ff1 + 1, ff1 + n + 1);
    res = max(res, ff1[n] + ff1[n - 1]);
    cout << res << '\n';
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