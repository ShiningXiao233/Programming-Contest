#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 3e5 + 100;
const int MOD = 998244353;

int a[N];
int n;
vector<int> q[N];
ll ans = 0;
void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        q[a[i]].push_back(i);
    }    
    
    for (int i = 1; i <= n; ++i) {
        ll tmp = 0;
        for (int j = 1; j < q[i].size(); ++j) {
            tmp += 1ll * j * (q[i][j] - q[i][j - 1] - 1);
            ans += tmp;
        }
    }
    cout << ans << endl;
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