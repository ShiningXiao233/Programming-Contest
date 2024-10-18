#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 4e5 + 100;
const int MOD = 998244353;
using ll = long long;
int n;
int a[N], v[N];

void sol() {
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) v[i] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], v[a[i]] = 1;
    vector<int> acc;
    for (int i = 1; i <= 2 * n; ++i) if (!v[i]) {
        acc.push_back(i);
    }
    int lr = 0, p1 = 0;
    for (int i = 1; i <= n; ++i) {
        while (lr < n && acc[lr] < a[i]) ++lr;
        if (lr == n) break;
        ++lr;
        p1 = i;
    }
    lr = n - 1;
    int p2 = n;
    for (int i = n; i > 0; --i) {
        while (lr >= 0 && acc[lr] > a[i]) --lr;
        if (lr == -1) break;
        --lr;
        p2 = i - 1;
    }
    // cout << p1 << ' ' << p2 << endl;
    cout << max(p1 - p2 + 1, 0) << '\n';

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
}