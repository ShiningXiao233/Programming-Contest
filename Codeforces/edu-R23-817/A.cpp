#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int sx, sy, ex, ey;
    int x, y;
    cin >> sx >> sy >> ex >> ey;
    sx = abs(sx - ex);
    sy = abs(sy - ey);
    cin >> x >> y;
    if (sx % x != 0 || sy % y != 0) {
        cout << "NO\n";
    } else {
        sx /= x;
        sy /= y;
        sx &= 1;
        sy &= 1;
        cout << ((sx ^ sy) ? "NO\n" : "YES\n"); 
    }
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