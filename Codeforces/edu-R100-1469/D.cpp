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
int cnt = 0;

void dfs(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 1 && b == 2) return;
    if (a == 1) {
        cnt = 100;
        return;
    }
    cnt ++;
    dfs(a, (b + a - 1) / a);
}

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cnt = 0;
        dfs(i, n);
        int p = i;
        // cout << i << ' ' << cnt << endl;
        if (cnt <= 8) {
            vector<pair<int, int>> res;
            for (int i = 2; i < p; ++i) {
                res.push_back(make_pair(i, i + 1));
            }
            for (int i = p + 1; i < n; ++i) {
                res.push_back(make_pair(i, i + 1));
            }
            int a = p, b = n, apos = p, bpos = n;
            while (1) {
                if (a < b) {
                    swap(a, b);
                    swap(apos, bpos);
                }
                if (a == 2 && b == 1) break;
                res.push_back(make_pair(apos, bpos));
                a = (a + b - 1) / b;

            }
            cout << res.size() << '\n';
            for (auto a : res) {
                cout << a.first << ' ' << a.second << '\n';
            }
            return;
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
    }
}