#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int X[103], Y[103], Z[103], W[103];
int n;
ll f[N];
void sol() {
    int res = 0;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
        
        if (X[i] < Y[i]) {
            W[i] = (X[i] + Y[i] + 1) / 2 - X[i];
        } else {
            W[i] = 0;
        }

        for (int j = N - 1; j >= Z[i]; --j) {
            f[j] = min(f[j], f[j - Z[i]] + W[i]);
        }
        res += Z[i];
    } 
    ll ans = 1e18;
    for (int i = res / 2 + 1; i <= res; ++i) {
        ans = min(ans, f[i]);
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