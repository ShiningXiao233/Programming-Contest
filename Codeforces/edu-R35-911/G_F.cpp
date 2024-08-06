#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100, B = 460;
const int MOD = 998244353;

int pos[N], Bl[B], Br[B];
bitset<B> col[B][103];
int n;

void sol() {
    int m, l, r, x, y;
    cin >> n;
    for (int l = 1, idx = 1; l <= n; l += B, idx ++) {
        int r = min(l + B - 1, n);
        Bl[idx] = l; Br[idx] = r;
        for (int i = l; i <= r; ++i) pos[i] = idx;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        int idx = pos[i];
        col[idx][x].set(i - Bl[idx]);
    }    
    cin >> m;
    while (m --) {
        cin >> l >> r >> x >> y;
        if (x == y) continue;
        if (pos[l] == pos[r]) {
            int idx = pos[l];
            for (int i = l; i <= r; ++i) {
                if (col[idx][x].test(i - Bl[idx])) {
                    col[idx][x].reset(i - Bl[idx]);
                    col[idx][y].set(i - Bl[idx]);
                }
            }
        } else {
            for (int i = pos[l] + 1; i < pos[r]; ++i) {
                col[i][y] |= col[i][x];
                col[i][x].reset();
            }
            int idx = pos[l];
            for (int i = l; i <= Br[idx]; ++i) {
                if (col[idx][x].test(i - Bl[idx])) {
                    col[idx][x].reset(i - Bl[idx]);
                    col[idx][y].set(i - Bl[idx]);
                }
            }
            idx = pos[r];
            for (int i = Bl[idx]; i <= r; ++i) {
                if (col[idx][x].test(i - Bl[idx])) {
                    col[idx][x].reset(i - Bl[idx]);
                    col[idx][y].set(i - Bl[idx]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int idx = pos[i];
        for (int j = 1; j <= 100; ++j) {
            if (col[idx][j].test(i - Bl[idx])) {
                cout << j << ' ';
                break;
            }
        }
    }
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