#include <iostream>
#include <cstring>

using namespace std;
int n, m;
const int MOD = static_cast<int>(1e9 + 7);

char s[260][260], t[260][260];
int dp[2][1 << 16][2], stat[260];
int chk[1 << 16];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    if (n < m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                t[j][i] = s[i][j];
            }
        }
        swap(n, m);
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                t[i][j] = s[i][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[i][j] == 'x') {
                stat[i] |= (1 << j);
            }           
        }
    }

    auto to_p = [] (int a, int b, int n) -> int {
        for (int i = 1; i < n; ++i) {
            if (!(b >> i & 1)) {
                a |= ((a >> (i - 1) & 1) << i);
            }
        }
        // for (int i = n - 2; i >= 0; --i) {
        //     if (!(b >> i & 1)) {
        //         a |= ((a >> (i + 1) & 1) << i);
        //     }
        // }
        return a;
    };
    // cout << to_p(1, 0, 2) << endl;
    

    int pre = 1, now = 0;
    dp[now][0][0] = 1;
    const int ST{(1 << m) - 1};
    for (int i = 0; i < m; ++i) {
        chk[ST ^ (1 << i)] = 1;
    }
    for (int i = 0; i < n; ++i) {
        swap(pre, now);
        memset(dp[now], 0, sizeof(dp[now]));
        // cout << stat[i] << endl;
        int gg = ST ^ stat[i];
        for (int st = 0; st <= ST; ++st) {
            for (int ff = 0; ff <= 1; ++ff) {
                if (dp[pre][st][ff] == 0) continue;
                int sg = gg & st;

                for (int g = gg; ; g = gg & (g - 1)) {
                    int p = to_p(g, stat[i], m) | sg | stat[i];
                    // cout << i << ' ' << st << ' ' << g << ' ' << p << " === " << endl;
                    if (p == ST) {
                        dp[now][g | sg][ff] += dp[pre][st][ff];
                        if (dp[now][g | sg][ff] >= MOD) {
                            dp[now][g | sg][ff] -= MOD;
                        }
                        // if (i == 1) {
                        // cout << i << " = " << st << ' ' << g << ' ' << p << ' ' << (g | sg)<< endl;
                    // }
                    }
                    if (chk[p] && ff == 0) {
                        dp[now][g | sg][1] += dp[pre][st][ff];
                        if (dp[now][g | sg][1] >= MOD) {
                            dp[now][g | sg][1] -= MOD;
                        }
                        // if (i == 1) {
                        // cout << i << " - " << st << ' ' << g << ' ' << p << ' ' << (g | sg)<< endl;
                    // }
                    }
                    if (g == 0) break;
                }
            }
            
        }
    }
    int ans = 0;
    for (int i = 0; i <= ST; ++i) {
        ans += dp[now][i][0];
        ans %= MOD;
        ans += dp[now][i][1];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}