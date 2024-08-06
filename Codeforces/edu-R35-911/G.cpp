#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100, B = static_cast<int>(2e5);
const int MOD = 998244353;

bitset<B> col[103];
int n;

void sol() {
    int m, l, r, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        col[x].set(i);
    }    
    cin >> m;
    while (m --) {
        cin >> l >> r >> x >> y;
        l --;
        r --;
        auto g = col[x];
        g = ((((g >> l) << l) << (B - r - 1)) >> (B - r - 1));
        col[y] |= g;
        col[x] ^= g;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (col[j].test(i)) {
                cout << j << ' ';
                break;
            }
        }
    }
    cout << '\n';
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