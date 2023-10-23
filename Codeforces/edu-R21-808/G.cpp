#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+100;

char s[N], t[N];
int ntx[N];
int fail[N][28];
int n;

void get_next(char *s, int *next, int n) {

    fail[0][s[1] - 'a'] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int a = 'a'; a <= 'z'; ++a) {
            if (s[i + 1] != a) {
                fail[i][a - 'a'] = fail[next[i]][a - 'a'];
            } else {
                fail[i][a - 'a'] = i + 1;
                next[i + 1] = fail[next[i]][a - 'a'];
            }
        }
    }
}

inline void to_str(int st, int val, char c, int *dp) {
    int ls = fail[st][c - 'a'];
    if (ls == n) val ++;
    dp[ls] = max(dp[ls], val);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s + 1;
    cin >> t + 1;
    n = strlen(t + 1);
    get_next(t, ntx, n);

    int *now, *pre;
    now = new int[n + 3];
    pre = new int[n + 3];
    memset(now, -0x3f, sizeof(int) * (n + 3));
    memset(pre, -0x3f, sizeof(int) * (n + 3));
    int lens = strlen(s + 1);
    now[0] = 0;
    for (int i = 1; i <= lens; ++i) {
        swap(now, pre);
        memset(now, -0x3f, sizeof(int) * (n + 3));
        for (int j = 0; j <= n; ++j) {
            if (pre[j] >= 0) {
                if (s[i] == '?') {
                    for (int a = 'a'; a <= 'z'; ++a) {
                        to_str(j, pre[j], a, now);
                    }
                } else {
                    to_str(j, pre[j], s[i], now);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(now[i], ans);
    }
    cout << ans << '\n';
    delete[] now;
    delete[] pre;
    return 0;
}