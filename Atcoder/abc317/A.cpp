#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n, h, x;
    cin >> n >> h >> x;
    x -= h;
    for (int i = 1; i <= n; ++i) {
        cin >> h;
        if (h >= x) {
            cout << i << endl;
            return;
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