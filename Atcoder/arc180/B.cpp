#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5+100;
int p[504], tp[504];
int n, k;
using Pair = pair<int, int>;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> tp[i], p[tp[i]] = i;
    vector<Pair> ans(0);
    for (int i = 1; i <= n; ++i) {
        int x = i;
        for (int j = i - 1; j > 0; --j) {
            if (p[j] - k >= p[x]) {
                ans.push_back(make_pair(p[x], p[j]));
                swap(p[x], p[j]);
                x = j;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
    return 0;
}