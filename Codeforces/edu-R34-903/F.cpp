#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int a[5];
const int GG[5] = {0, 0x1, 0x33, 0x777, 0xFFFF};

int n;
char s[4][1003];
int dp[2][1 << 12];

void sol() {
    scanf("%d", &n);
    for (int i = 1; i <= 4; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < 4; ++i) {
        scanf("%s", s[i] + 1);
    }        
    memset(dp, 0x3f, sizeof(dp));
    int now = 1, pre = 0;
    dp[now][0] = 0;
    const int ST = (1 << 12), GS = 0xffff;
    for (int i = 1; i <= n; ++i) {
        now ^= 1; pre ^= 1;
        memset(dp[now], 0x3f, sizeof(dp[now]));
        int ak = 0;
        for (int j = 0; j < 4; ++j) {
            if (s[j][i] == '*') ak |= (1 << j);
        }
        for (int j = 0; j < ST; ++j) {
            if (dp[pre][j]  > 1000000000) continue;
            int nbit = (j << 4) | ak;
            for (int a1 = 0; a1 <= 4; ++a1) {
                if (a1 > i) break;
                for (int a2 = 0; a2 <= 3; ++a2) {
                    if (a2 > i) break;
                    for (int a3 = 0; a3 <= 2; ++a3) {
                        if (a3 > i) break;
                        for (int a4 = 0; a4 <= 1; ++a4) {
                            int tmp = nbit & (GS ^ GG[a1]);
                            tmp = tmp & (GS ^ (GG[a2] << 1));
                            tmp = tmp & (GS ^ (GG[a3] << 2));
                            tmp = tmp & (GS ^ (GG[a4] << 3));
                            if ((tmp >> 12) > 0) {
                                continue;
                            } else {
                                dp[now][tmp] = min(dp[pre][j] + a[a1] + a[a2]
                                + a[a3] + a[a4], dp[now][tmp]);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", dp[now][0]);
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