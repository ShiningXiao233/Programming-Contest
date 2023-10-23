#include <iostream>

using namespace std;

class comb {

public:
    static const int MOD = 1e9 + 7;
    comb(int _n);
    int qp(int x, int p = MOD - 2) {
        int res = 1;
        while (p) {
            if (p & 1) res = 1ll * x * res % MOD;
            p >>= 1;
            x = 1ll * x * x % MOD;
        }
        return res;
    }
    int C(int n, int m) {
        return 1ll * f[n] * rf[m] % MOD * rf[n - m] % MOD;
    }
    int A(int n, int m) {
        return 1ll * f[n] * rf[n - m] % MOD;
    }
    int F(int n) {
        return f[n];
    }
    int RF(int n) {
        return rf[n];
    }
    ~comb();
private:
    
    const int n;
    int *f, *rf;
};

int main() {
    int n, m;
    cin >> n >> m;
    comb CB(m + 3);
    int res = 0, p = 1;
    for (int i = 0; i <= n; ++i) {
        res += 1ll * CB.C(n, i) * CB.A(m - i, n - i) % CB.MOD * p;
        res %= CB.MOD;
        p *= -1;
    }
    res = 1ll * (res + CB.MOD) * CB.A(m, n) % CB.MOD;
    cout << res << '\n';
    return 0;
}

comb::comb(int _n) : n(_n) {
    f = new int[n + 1];
    rf = new int[n + 1];
    f[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = 1ll * f[i - 1] * i % MOD;
    rf[n] = qp(f[n]);
    for (int i = n; i >= 1; --i) rf[i - 1] = 1ll * rf[i] * i % MOD;
}

comb::~comb()
{
    delete[] f;
    delete[] rf;
}
