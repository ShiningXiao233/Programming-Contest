#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    int ans = 0;
    string a;
    cin >> a;
    map<int, int> g;    
    g[0] = 0;
    int sum = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == '0') sum --;
        else sum ++;
        if (g.count(sum)) {
            ans = max(ans, i + 1 - g[sum]);
        } else {
            g[sum] = i + 1;
        }
    }
    cout << ans << '\n';
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