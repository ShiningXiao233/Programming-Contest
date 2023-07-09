#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 206;
const int MOD = 998244353;

int f[2][N][1 << 12];
int n, X;
int tp[N];
#define getbit(x) ((1 << (x)) - 1)

void sol() {
    cin >> n >> X;
    X --;
    int a = 0, b = 1;
    f[a][0][0] = 1;
    // cout << getbit(X + 1) << '\n';
    int sta = (1 << (X + X + 1));
    for (int i = 0; i < n; ++i) {
        memset(f[b], 0, sizeof(f[b]));
        for (int j = 0; j <= i; ++j) {
            for (int st = 0; st < sta; ++st) {
                // if (f[a][j][st] > 0) {
                    int nst = st >> 1;
                    // if (i + 1 + X > n) nst |= (1 << (X + X));
                    f[b][j][nst] = (f[b][j][nst] + f[a][j][st]) % MOD;
                    for (int k = 2 * X; k >= 0; --k) {
                        if ((nst >> k) & 1) continue;
                        if (i + 1 + k - X <= n && i + 1 + k - X >= 1)
                        f[b][j + 1][nst | (1 << k)] = (f[b][j + 1][nst | (1 << k)] + f[a][j][st]) % MOD;
                    }
                // }
            }
        }
        a ^= 1;
        b ^= 1;
    }
    tp[0] = 1;
    for (int i = 1; i < N; ++i) {
        tp[i] = 1ll * tp[i - 1] * i % MOD;
    }
    int ans = 0, p = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < sta; ++j) {
            ans += 1ll * p * f[a][i][j] * tp[n - i] % MOD;
            ans = (ans % MOD + MOD) % MOD;
        }
        p *= -1;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        sol();
    }
}

/* #include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 206;
const int MOD = 998244353;

int f[2][N][1 << 12];
int n, X;
int tp[N];
#define getbit(x) ((1 << (x)) - 1)

void sol() {
    cin >> n >> X;
    X --;
    int a = 0, b = 1;
    f[a][0][getbit(X + 1)] = 1;
    // cout << getbit(X + 1) << '\n';
    int sta = (1 << (X + X + 1));
    for (int i = 0; i < n; ++i) {
        memset(f[b], 0, sizeof(f[b]));
        for (int j = 0; j <= i; ++j) {
            for (int st = 0; st < sta; ++st) {
                // if (f[a][j][st] > 0) {
                    int nst = st >> 1;
                    if (i + 1 + X > n) nst |= (1 << (X + X));
                    f[b][j][nst] = (f[b][j][nst] + f[a][j][st]) % MOD;
                    for (int k = 2 * X; k >= 0; --k) {
                        if ((nst >> k) & 1) continue;
                        f[b][j + 1][nst | (1 << k)] = (f[b][j + 1][nst | (1 << k)] + f[a][j][st]) % MOD;
                    }
                // }
            }
        }
        a ^= 1;
        b ^= 1;
    }
    tp[0] = 1;
    for (int i = 1; i < N; ++i) {
        tp[i] = 1ll * tp[i - 1] * i % MOD;
    }
    int ans = 0, p = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < sta; ++j) {
            ans += 1ll * p * f[a][i][j] * tp[n - i] % MOD;
            ans = (ans % MOD + MOD) % MOD;
        }
        p *= -1;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
}

int main() {
    int T = 1;
    while (T--) {
        sol();
    }
}

*/