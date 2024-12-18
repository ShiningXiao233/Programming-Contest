#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        mp[x] ++;
        ans = max(ans, mp[x]);   
    }
    cout << n - ans << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}