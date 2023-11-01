#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class RMQ {

public:
    RMQ(int n, int k, int *a) : N(n), LOGN(log2(n) + 1), MOD(k) {
        val = new int*[LOGN];
        for (int i = 0; i < LOGN; ++i) {
            val[i] = new int[N];
        }
        for (int i = 0; i < N; ++i) {
            val[0][i] = a[i] % MOD;
        }
        for (int i = 1; i < LOGN; ++i) {
            for (int j = 0; j + (1 << i) < N; ++j) {
                val[i][j] = 1ll * val[i - 1][j] * val[i - 1][j + (1 << (i - 1))] % MOD;
            }
        }
    }
    ~RMQ() {
        for (int i = 0; i < LOGN; ++i) {
            delete[] val[i];
        }
        delete[] val;
    }
    int get(int l, int r) {
        int res = 1;
        for (int i = LOGN - 1; i >= 0; --i) {
            if (l + (1 << i) < r) {
                res = 1ll * res * val[i][l] % MOD;
                l += (1 << i);
            }
        }
        return 1ll * res * val[0][l] % MOD;
    }
private:
    const int N, MOD, LOGN;
    int **val;

};

const int N = 1e5+10;
int n, k;
int a[N];
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    RMQ res(n, k, a);
    long long tans = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = i, ans = -1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (res.get(mid, i + 1) == 0) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        tans += ans + 1;
    }
    cout << tans << endl;
    return 0;
}