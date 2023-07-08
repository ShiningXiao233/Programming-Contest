#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;


char a[103][103];
char b[103][103];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] + 1;
    }    
    for (int i = 1; i <= n; ++i) {
        b[1][i + 1] = a[1][i];
        b[n][i - 1] = a[n][i];
        b[i - 1][1] = a[i][1];
        b[i + 1][n] = a[i][n];
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < n; ++j) {
            b[i][j] = a[i][j];
        }
    }
    b[1][n + 1] = 0;
    for (int i = 1; i <= n; ++i) {
        cout << b[i] + 1 << '\n';
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
}