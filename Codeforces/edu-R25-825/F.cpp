#include <iostream>
#include <cstring>

using namespace std;
const int N = 8003;

char s[N];
int nt[N][N];
int n;

void get_next(char *s, int *next, int n) {
    next[1] = 0;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && s[j + 1] != s[i]) j = next[j];
        if (s[j + 1] == s[i]) ++j;
        next[i] = j;
    }
}

int get(int x) {
    int cnt = 0;
    while (x > 0) {
        ++cnt;
        x /= 10;
    }
    return cnt;
}

int dp[N];

int main() {
    cin >> s + 1;
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = i + 1;
        get_next(s + i - 1, nt[i], n - i + 1);
    }
    // cout << 11 << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            int len = i - j + 1;
            int tmp = len + 1;
            if (len % (len - nt[j][len]) == 0) {
                tmp = get(len / (len - nt[j][len])) + (len - nt[j][len]);
            }
            dp[i] = min(dp[i], dp[j - 1] + tmp);
        }
    }
    cout << dp[n] << endl;
    return 0;
}