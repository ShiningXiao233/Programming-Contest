#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) cin >> l[i];
    sort(l.begin(), l.end(), greater<int>());
    vector<int> sum(410000, 0);
    sum[0] = 1;
    sum[1] = -1;
    int ss = 0, ans = -1;
    for (int i = 0, j = 0; i < sum.size() ; ++i) {
        ss += sum[i];
        sum[i + 1] += sum[i];
        // cout << i + 1 << ' ' << sum[i + 1] << endl;
        // cout << i << ' ' << sum[i] << ' ' << ss + sum[i + 1] << endl;
        if (ss + sum[i + 1] >= k) {
            ans = i + 1;
            break;
        }
        for (; j < n && sum[i] > 0; ++j) {
            sum[i] --;
            sum[i + 2] += 2;
            int a = (l[j] - 1) / 2;
            int b = (l[j] - 1 - a);
            // cout << a <<  ' ' << 
            sum[i + 2 + a] --;
            sum[i + 2 + b] --;
            ss --;
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
}