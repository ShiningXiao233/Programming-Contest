#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

int pos[N], tpos[N * 3];

void sol() {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n * 3; ++i) {
        cin >> x;
        if (pos[x] == 0) pos[x] = -1;
        else if (pos[x] == -1) {
            pos[x] = i, tpos[i] = x;
            // cout << x << ' ' << i << "--\n";
        } 
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << pos[i] << '\n';
    // }
    for (int i = 1; i <= n * 3; ++i) {
        if (tpos[i] != 0) {
            cout << tpos[i] << ' ';
        }
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