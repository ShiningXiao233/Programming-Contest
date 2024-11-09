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

map<int, vector<int>> G;
int a[N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] ^= a[i - 1];
    G.clear();
    for (int i = 0; i <= n; ++i) {
        G[a[i]].push_back(i);
    }   
    int l, r; 
    while (m --) {
        
        cin >> l >> r;
        if (a[r] == a[l - 1]) {
            cout << "YES\n";
        } else {
            // cout << "--" << a[l - 1] << ' ' << a[r] << endl;
            auto& s1 = G[a[l - 1]];
            auto& s2 = G[a[r]];
            auto s2pos = upper_bound(s2.begin(), s2.end(), l - 1);
            auto s1pos = lower_bound(s1.begin(), s1.end(), r);
            if (s2pos == s2.end() || s1pos == s1.begin()) {
                cout << "NO\n";
            } else {
                // cout << *s1pos << ' ' << *s2pos << endl;
                s1pos --;
                if (*s1pos > *s2pos) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // break;
    }
}