#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        int flag =0;
        for (int j = 1; j <= 9; ++j) {
            if (n % j == 0) {
                if (i % (n / j) == 0) {
                    cout << j;
                    flag = 1;
                    break;
                }
            }
            
        }
        if (flag == 0) cout << "-";
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