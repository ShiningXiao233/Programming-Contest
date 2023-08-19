#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int d[N];
void sol() {
    int m;
    cin >> m;
    int ff = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> d[i];
        ff += d[i];
    } 
    ff /= 2;
    ff += 1;
    for (int i = 1; i <= m; ++i) {
        if (ff <= d[i]) {
            cout << i << ' ' << ff << '\n';
            return;
        }
        ff -= d[i];
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