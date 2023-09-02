#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2e5+100;
const int MOD = 998244353;


int f[N];
int n, d, p;
void sol() {
    cin >> n >> d >> p;
    for (int i = 1; i <= n; ++i) cin >> f[i];
    sort(f + 1, f + n + 1);
    ll res = 0, ans = 0, tmp = 0;
    int dd = d;
    for (int i = n; i > 0; --i) {
        dd --;
        tmp += f[i];
        if (dd == 0 || i == 1) {
            if (tmp >= p) {
                ans += p;
            } else {
                ans += tmp;
            }
            tmp = 0;
            dd = d;
        } 
    }
    cout << ans << '\n';
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