#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;
const int N = 1e6 + 100;
const int MOD = 998244353;
int a[N], p[N];
int n;

void sol() {
    cin >> n;
    ll ans = 0, tmp = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tmp += i - p[a[i]];
        p[a[i]] = i;
        ans += tmp;
    }
    ans = ans * 2 - n;
    cout << fixed << setprecision(10) << 1.0 * ans / (1.0 * n * n) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        sol();
    }
    exit(0);
}