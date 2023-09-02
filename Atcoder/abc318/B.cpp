#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e2 + 100;
const int MOD = 998244353;
bool s[N][N];

void sol() {
    int n;
    cin >> n;
    int a, b, c, d;
    while (n--) {
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; ++i) {
            for (int j = c; j < d; ++j) {
                s[i][j] = 1;
            }
        }   
    }
     
    int res = 0;
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            res += s[i][j];
        }
    }
    cout << res << endl;
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