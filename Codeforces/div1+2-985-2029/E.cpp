#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 4e5 + 100;
const int MOD = 998244353;
using ll = long long;
int f[N];
int a[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool chk(int a, int b) {
    if (b % a == 0) return 1;
    // if (b - f[b] >= 2 * a) return 1;
    if ((a + f[b] - 1) / f[b] * f[b] * 2 <= b) return 1;
    return 0;
}

void sol() {
    int n, x;
    cin >> n;
    int ans = 2;
    int g = 0;
    int pri = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; g = gcd(g, a[i]);
        if (f[a[i]] == a[i]) pri == -1 ? pri = a[i] : pri = min(pri, a[i]);
    }
    if (g >= 2) {
        cout << g << '\n';
        return;
    } {
        if (pri == -1) {
            cout << 2 << '\n';
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!chk(pri, a[i])) {
                cout << -1 << '\n';
                return;
            }
        }
        cout << pri << '\n';
    }
}

int main() {
    for (int i = 2; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            if (!f[j]) f[j] = i;
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}