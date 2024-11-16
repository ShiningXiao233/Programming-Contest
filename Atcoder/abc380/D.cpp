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
#define rv(x) (x >= 'a' ? x - 32 : x + 32)
void sol() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q --) {
        ll x;
        cin >> x;
        ll a = (x - 1) / s.size() + 1;
        ll p = x % s.size();
        if (p == 0) p = s.size() - 1;
        else p --;
        int cnt = 0;
        for (int i = 0; i < 60; ++i) {
            if (((a >> i) & 1) == 0) cnt ^= 1;
            else break;
        } 
        for (int i = 0; i < 60; ++i) {
            if ((a >> i) & 1) cnt ^= 1;
        }
        cnt ^= 1;
        if (cnt == 0) cout << s[p] << ' ';
        else cout << char(rv(s[p])) << ' ';
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
}