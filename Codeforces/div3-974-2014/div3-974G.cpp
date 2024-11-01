#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <deque>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;
int n, m, k;
using Pair = pair<int, int>;

void sol() {
    cin >> n >> m >> k;
    vector<Pair> a(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        a[i + n] = {a[i].first + k, 0};
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int l = 0, r = -1;
    ll sum = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
        int now = a[i].first;
        // cout << now << " ----- " << endl;
        ++r;
        a[r] = a[i];
        sum += a[r].second;
        while (l < r && now - a[l].first >= k) {
            sum -= a[l].second;
            ++l;
        }
        // cout << "sum = " << sum << endl;
        auto z = min(sum / m, 1ll * (a[i + 1].first - now));
        ll needp = min(sum, 1ll * (a[i + 1].first - now) * m);
        ans += z;
        sum -= needp;

        while (needp) {
            if (a[r].second <= needp) {
                needp -= a[r].second;
                r --;
            } else {
                a[r].second -= needp;
                needp = 0;
            }
        }
        // cout << now << ' ' << z << ' ' << sum << endl;
    }
    cout << ans << '\n';

}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}