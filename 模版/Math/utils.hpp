#pragma once

namespace Math_utils {

const int MOD = 998244353;
const int N = static_cast<int>(1e5);
int f[N], rf[N];
/**
 * 快速幂
 */
template<typename T = int>
T qpow(T x, T q) {
    T res = 1;
    for (; q; q >>= 1, x = x * x % MOD) {
        if (q & 1) res = res * x % MOD;
    }
    return res;
}

void pre_comb() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = 1ll * f[i - 1] * i % MOD;
    rf[N - 1] = qpow<int>(f[N - 1], MOD - 2);
    for (int i = N - 1; i > 0; --i) {
        rf[i - 1] = 1ll * rf[i] * i % MOD;
    }
}

/**
 * 组合数 C(n, m) 即从n中选m个
 */
int comb(int n, int m) {
    static bool flag = false;
    if (!flag) {
        flag = true;
        pre_comb();
    }
    if (m > n || n < 0 || m < 0) return 0;
    return 1ll * f[n] * rf[n - m] % MOD * rf[m] % MOD;
}

int Catalan(int n) {
    return (comb(n * 2, n) - comb(2 * n, n - 1) + MOD) % MOD;
}

}