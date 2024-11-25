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

int n, q;

vector<int> p1, px, p2;



int get_ans(int L, int R) {
    auto itx = lower_bound(px.begin(), px.end(), L);
    if (itx == px.end() || *itx > R) return 0;

    int ans = 1;
    int l = 1, r = (R - L);
    auto itl = lower_bound(p1.begin(), p1.end(), L);
    if (itl == p1.end() || *itl >= R) return ans;
    auto itr = upper_bound(p2.begin(), p2.end(), R);
    if (itr == p2.begin()) return ans;
    
    auto chk = [&itl, &itr](int x) -> bool {
        if (p1.end() - itl < x) return false;
        if (itr - p2.begin() < x) return false;
        int posl = *(itl + x - 1);
        int posr = *(itr - x);
        auto it = upper_bound(px.begin(), px.end(), posl);
        if (it == px.end() || *it > posr) return false;
        return true;
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (chk(mid)) {
            ans = mid * 2 + 1;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
    
}

void sol() {
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') p1.push_back(i);
        else if (s[i] == '2') p2.push_back(i);
        else px.push_back(i);
    }
    while (q --) {
        int L, R;
        cin >> L >> R;
        L --, R --;
        cout << get_ans(L, R) << '\n';
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