#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5003;

int dp[N][N];
int n;
int a[N], tlen[100002], g7[10];


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }    
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            tlen[a[j]] = 0;
        }
        memset(g7, 0, sizeof(g7));
        for (int j = 1; j < i; ++j) {
            tlen[a[j]] = max(tlen[a[j]], dp[i][j]);
            g7[a[j] % 7] = max(g7[a[j] % 7], dp[i][j]);
        }
        for (int j = i + 1; j <= n; ++j) {
            dp[i][j] = max({dp[i][0], g7[a[j] % 7], tlen[a[j] - 1], tlen[a[j] + 1]}) + 1;
            dp[j][i] = dp[i][j];
            tlen[a[j]] = max(tlen[a[j]], dp[i][j]);
            g7[a[j] % 7] = max(g7[a[j] % 7], dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}