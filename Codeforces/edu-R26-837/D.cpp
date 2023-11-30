#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n, k;
short dp[203][6002];

#define Max(x, y) (x > y ? x : y)
#define Min(x, y) (x < y ? x : y)

int main() {
    cin >> n >> k; 
    int pre = 0, now = 1;   
    ll x = 0;
    short n5, n2;
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        n5 = n2 = 0;
        while (x % 2 == 0) n2 ++, x /= 2;
        while (x % 5 == 0) n5 ++, x /= 5;
        for (int i = k; i > 0; --i) {
            for (int j = 6000; j >= 0; --j) {
                if (j >= n5) {
                    dp[i][j] = Max(dp[i][j], dp[i - 1][j - n5] + n2);
                }
            }
        }
        swap(pre, now);
    }
    short ans = 0;
    for (int i = 0; i < 6000; ++i) {
        ans = Max(ans, Min(i, dp[k][i]));
    }
    cout << ans << endl;
    return 0;
}