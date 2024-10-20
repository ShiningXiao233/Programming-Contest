#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int inf = 1e9;

vector<pair<int, int>> num_move(int n, int from, int to, int ng) {
    vector<pair<int, int>> res;
    int pp = n - ng; from = (from + pp) % n; to = (to + pp) % n; ng = 0;
    pp = n - pp;
    if (to != ng) {
        res.emplace_back(abs(from - to), pp);
    }
    if (to < from) {
        res.emplace_back(n - abs(from - to) + to + 1, (to + 1 + pp) % n);
        if (to == 0) {
            res.emplace_back(abs(from - to) + 1, (to - 1 + pp + n) % n);
        }
    } else {
        res.emplace_back(n - abs(from - to) + n - to + 1, (to - 1 + pp + n) % n);
    }
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector dp(q + 1, vector<int>(n, inf));
    int ph = 0, pt = 0;
    dp[0][1] = 0;
    for (int i = 0; i < q; i++) {
        char hc;
        int t;
        cin >> hc >> t;
        --t;
        int h = (hc == 'L' ? 0 : 1);
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == inf) continue;
            vector<int> pos(2);
            pos[ph] = pt;
            pos[ph ^ 1] = j;
            for (auto [num, npos]: num_move(n, pos[h], t, pos[h ^ 1])) {
                dp[i + 1][npos] = min(dp[i + 1][npos], dp[i][j] + num);
            }
        }
        ph = h, pt = t;
    }
    int ans = inf;
    for (int i = 0; i < n; i++) ans = min(ans, dp[q][i]);
    cout << ans << endl;
}
