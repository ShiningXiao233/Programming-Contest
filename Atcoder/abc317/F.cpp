#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
ll n, a, b, c;

ll f[64][2][2][2][12][12][12];

bool get(int a, int b, int c, int t, int a1, int b1, int c1) {
    if (a && a1 > t) return 0;
    if (b && b1 > t) return 0;
    if (c && c1 > t) return 0;
    return 1;
}

void sol() {
    cin >> n >> a >> b >> c;
    f[62][1][1][1][0][0][0] = 1;
    for (int i = 61; i >= 0; --i) {
        int bit_i = (n >> i) & 1;
        for (int a1 = 0; a1 < 2; ++a1) {
            for (int b1 = 0; b1 < 2; ++b1) {
                for (int c1 = 0; c1 < 2; ++c1) {
                    for (int r1 = 0; r1 < a; ++r1) {
                        for (int r2 = 0; r2 < b; ++r2) {
                            for (int r3 = 0; r3 < c; ++r3) {
                                for (int p1 = 0; p1 < 2; ++p1) {
                                    for (int p2 = 0; p2 < 2; ++p2) {
                                        int p3 = p1 ^ p2;
                                        if (get(a1, b1, c1, bit_i, p1, p2, p3)) {
                                            int a2 = (a1 & (p1 == bit_i));
                                            int b2 = (b1 & (p2 == bit_i));
                                            int c2 = (c1 & (p3 == bit_i));
                                            f[i][a2][b2][c2]\
                                            [(r1 * 2 + p1) % a]\
                                            [(r2 * 2 + p2) % b]\
                                            [(r3 * 2 + p3) % c]\
                                            += f[i + 1][a1][b1][c1][r1][r2][r3];

                                            f[i][a2][b2][c2]\
                                            [(r1 * 2 + p1) % a]\
                                            [(r2 * 2 + p2) % b]\
                                            [(r3 * 2 + p3) % c]\
                                            %= MOD;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    ll res = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                res += f[0][i][j][k][0][0][0];
            }
        }
    }
    res %= MOD;
    ll g1 = a * b / __gcd(a, b);
    ll g2 = a * c / __gcd(a, c);
    ll g3 = c * b / __gcd(c, b);
    g1 = (n / g1) % MOD;
    g2 = (n / g2) % MOD;
    g3 = (n / g3) % MOD;
    res -= g1 + g2 + g3 + 1;
    res = (res % MOD + MOD) % MOD;
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