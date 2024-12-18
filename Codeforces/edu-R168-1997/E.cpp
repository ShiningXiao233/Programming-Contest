#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;

int n, q;

vector<int> band[N];
int a[N];

int chk(int x, int l, int r) {
    int res = 0;
    for (int i = l; i < min(r, n + 1); ++i) res += (a[i] >= x);
    return res;
}

void ss(vector<int>& s, int x) {
    int pos = 1, nowlevel = 1;
    
    while (pos <= n) {
        s.push_back(pos);
        int sp = 1;
        int p = pos;
        int nowcnt = 0;

        while (1) {
            int tcnt = chk(nowlevel, p, p + sp);
            if (nowcnt + tcnt <= x) {
                p = p + sp;
                sp <<= 1;
                nowcnt += tcnt;
                if (p > n) break;
            } else {
                sp >>= 1;
                break;
            }
        }

        while (sp > 0 && p <= n) {
            int tcnt = chk(nowlevel, p, p + sp);
            if (nowcnt + tcnt <= x) {
                p += sp;
                nowcnt += tcnt;
            }
            sp >>= 1;
        }

        nowlevel ++;
        pos = p;
    }
}

void sol() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ss(band[i], i);
    }
    while (q --) {
        int i, x;
        cin >> i >> x;
        auto it = upper_bound(band[x].begin(), band[x].end(), i) - band[x].begin();
        if (it <= a[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
}