#include <iostream>

using namespace std;
char s[102][102], t[102][102];

bool chk(int n, int m, char s[][102]) {
    if (n % 3 > 0) return 0;
    char a = s[1][1];
    for (int i = 1; i <= n / 3; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] != a) return 0;
        }
    }
    if (a == s[n / 3 + 1][1]) return 0;

    a = s[n / 3 + 1][1];
    for (int i = n / 3 + 1; i <= n / 3 * 2; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] != a) return 0;
        }
    }
    if (a == s[n / 3 * 2 + 1][1] || s[n / 3 * 2 + 1][1] == s[1][1]) return 0;
    
    a = s[n / 3 * 2 + 1][1];
    for (int i = n / 3 * 2 + 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] != a) return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        for (int j = 1; j <= m; ++j) {
            t[j][i] = s[i][j];
        }
    }
    if (chk(n, m, s) || chk(m, n, t)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}