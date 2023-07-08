#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;
const int CG = 6, MOD = 998244353;
ll n, m;
char s[200][10];
bool fg[100];

struct mkx
{
    int a[1 << CG][1 << CG];
    void init(int k) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < (1 << CG); ++i) 
            a[i][i] = k;
    }
    mkx operator* (const mkx oth) const {
        mkx res;
        res.init(0);
        for (int i = 0; i < (1 << CG); ++i) {
            for (int j = 0; j < (1 << CG); ++j) {
                for (int k = 0; k < (1 << CG); ++k) {
                    res.a[i][j] = (1ll * a[i][k] * oth.a[k][j] + res.a[i][j]) % MOD;
                }
            }
        }
        return res;
    }
    /* data */
} ST;



bool chk(int x, int n) {
    char t[10] = {0};
    for (int i = 0; i < n; ++i) {
        if ((x >> i) & 1) t[i] = 'a';
        else t[i] = 'b';
    }
    for (int j = 1; j <= m; ++j) {
        char *c = strstr(t, s[j]);
        if (c != NULL) return 0;
    }
    // cout << t << '\n';
    return 1;
}

int qp(ll p) {
    mkx res, x = ST;
    res.init(1);
    while (p) {
        if (p & 1ll) res = res * x;
        p >>= 1;
        x = x * x;
    }
    int ans = 0;
    for (int j = 0; j < (1 << CG); ++j) {
        for (int i = 0; i < (1 << CG); ++i) {
            ans += 1ll * fg[i] * res.a[i][j] % MOD;
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
    }
    if (n <= 6) {
        int ans = 0;
        for (int i = (1 << n) - 1; i >= 0; --i) {
            if (chk(i, n)) ans ++;
        }
        cout << ans << '\n';
    } else {
        for (int i = 0; i < (1 << CG); ++i) {
            fg[i] = chk(i, CG);
        }
        for (int i = 0; i < (1 << CG); ++i) {
            for (int p = 0; p < 2; ++p) {
                int b = (i >> 1) | (p << 5);
                ST.a[i][b] = fg[b];
            }
        }
        cout << qp(n - 6) << '\n';
    }
    return 0;
}