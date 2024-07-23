#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5+100;
const int MOD = 998244353;

int qp(int x, int p = MOD - 2) {
    x %= MOD;
    int res = 1;
    while (p) {
        if (p & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    int q1 = 1, qo = 0;
    int nn = 1ll * n * n % MOD;
    int rn = qp(nn);
    int n_2 = 1ll * n * (n - 2) % MOD;
    for (int i = 0; i < k; ++i) {
        q1 = (1ll * n_2 * rn % MOD * q1 % MOD + 2ll * rn % MOD) % MOD; 
        qo = (1ll * n_2 * rn % MOD * qo % MOD + 2ll * rn % MOD) % MOD; 
    }
    int ff = 1ll * (2 + n) * (n - 1) / 2 % MOD;
    cout << (q1 + 1ll * ff * qo) % MOD << endl; 
    return 0;
}