#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

int f[(1 << 15) + 2];

int n, m;

char s[(1 << 12) + 3], ls[(1 << 12) + 3];
int ans = 0;

int get_fa(int x) {
    return x == f[x] ? x : (f[x] = get_fa(f[x]));
}

void mg(int a, int b) {
    a = get_fa(a);
    b = get_fa(b);
    if (a != b) {
        f[a] = f[b];
        ans --;
    }
}

void sol() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i) {
        swap(s, ls);
        cin >> s;
        int cnt = m;
        char pre = 0;
        for (int i = 0; i < m / 4; ++i) {
            s[i] = ((s[i] <= '9') ? (s[i] - '0') : (s[i] - 'A' + 10));
            for (int j = 0; j < 4; ++j) {
                char bit = (s[i] >> (3 - j) & 1);
                // cout << int(bit);
                char lsbit = (ls[i] >> (3 - j) & 1);
                f[cnt] = cnt;
                if (bit == 1) {
                    ans ++;
                    if (pre) mg(cnt - 1, cnt);
                    if (lsbit) mg(cnt - m, cnt);
                }
                cnt ++;
                pre = bit;
            }
        }
        // cout << '\n';
        for (int j = 0; j < m; ++j) {
            f[j] = f[j + m] - m;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}