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

int get_p (int a, int b, int c, int f, int n) {
    int ans = 0;
    while (a != c) {
        a += f;
        a = (a + n) % n;
        if (a == b) return 10000;
        ans ++;
    }
    return ans;
}

void sol() {
    int n, q;
    cin >> n >> q;
    int L = 0, R = 1;
    int ans = 0;
    while (q --) {
        char c;
        int p;
        cin >> c >> p;
        p --;
        
        if (c == 'L') {
            ans += min(get_p(L, R, p, 1, n), get_p(L, R, p, -1, n));
            L = p;
        } else {
            ans += min(get_p(R, L, p, 1, n), get_p(R, L, p, -1, n));

            R = p;
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
}