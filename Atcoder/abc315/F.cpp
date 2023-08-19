#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int N = 1e4 + 100;
const int MOD = 998244353;
double f[N][40];
double X[N], Y[N];
double S[N], tt[N];
int n;

#define gg(a, b) sqrt((X[a] - X[b]) * (X[a] - X[b]) + (Y[a] - Y[b]) * (Y[a] - Y[b]))

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i] >> Y[i];
        for (int j = 0; j < 40; ++j) {
            f[i][j] = 1e30;
        }
    }
    tt[0] = 0;
    tt[1] = 1;
    for (int i = 2; i <= 100; ++i) {
        tt[i] = tt[i - 1] * 2.0;
    }
    f[1][0] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int k = 0; k < 40; ++k) {
            for (int j = 0; i - j - 1 >= 1 && j + k < 40; ++j) {
                int p = i - j - 1;
                f[i][j + k] = min(f[i][j + k], f[p][k] + gg(i, p));
            }
        }
    }
    double res = 1e30;
    for (int i = 0; i < 40; ++i) {
        res = min(res, f[n][i] + tt[i]);
    }
    printf("%.10f\n", res);
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