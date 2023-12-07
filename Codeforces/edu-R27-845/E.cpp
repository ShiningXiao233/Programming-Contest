#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
int x[504], y[504];

#include <vector>

bool chk(int t) {
    int x1 = n + 1, x2 = 0, y1 = m + 1, y2 = 0;
    vector<int> row(0), col(0);
    row.insert(row.end(), {0, 1, n});
    col.insert(col.end(), {0, 1, m});
    for (int i = 0; i < k; ++i) {
        int _x = max(x[i] - t, 1);
        row.push_back(_x);
        if (_x > 1) row.push_back(_x - 1);
        if (_x <= n) row.push_back(_x + 1);

        _x = min(x[i] + t + 1, n + 1);
        row.push_back(_x);
        if (_x > 1) row.push_back(_x - 1);
        if (_x <= n) row.push_back(_x + 1);
        int _y = max(y[i] - t, 1);
        col.push_back(_y);
        if (_y > 1) col.push_back(_y - 1);
        if (_y <= m) col.push_back(_y + 1);
        _y = min(y[i] + t, m);
        col.push_back(_y);
        if (_y > 1) col.push_back(_y - 1);
        if (_y <= m) col.push_back(_y + 1);
        
    }
    sort(row.begin(), row.end());
    row.erase(unique(row.begin(), row.end()), row.end());

    sort(col.begin(), col.end());
    col.erase(unique(col.begin(), col.end()), col.end());
    
    using Pair = pair<int, int>;
    vector<Pair> midy[row.size()];
    vector<int> num(col.size()), tmp(col.size());

    for (int i = 0; i < k; ++i) {
        int _x = max(x[i] - t, 1);
        int _y1 = max(y[i] - t, 1), _y2 = min(y[i] + t + 1, m + 1);
        _x = lower_bound(row.begin(), row.end(), _x) - row.begin();
        _y1 = lower_bound(col.begin(), col.end(), _y1) - col.begin();
        _y2 = lower_bound(col.begin(), col.end(), _y2) - col.begin();
        midy[_x].push_back(make_pair(_y1, -_y2));
        _x = min(x[i] + t + 1, n + 1);
        _x = lower_bound(row.begin(), row.end(), _x) - row.begin();
        midy[_x].push_back(make_pair(-_y1, _y2));
    }
    for (int i = 1; i < row.size(); ++i) {
        if (row[i] == n + 1) break;
        for (int j = 0; j < tmp.size(); ++j) tmp[j] = 0;
        for (Pair x : midy[i]) {
            tmp[abs(x.first)] += x.first / abs(x.first);
            tmp[abs(x.second)] += x.second / abs(x.second);
        }
        for (int j = 1; j < col.size(); ++j) {
            if (col[j] == m + 1) break;
            tmp[j] += tmp[j - 1];
            num[j] += tmp[j];
            if (num[j] == 0) {
                x1 = min(x1, row[i]);
                y1 = min(y1, col[j]);

                x2 = max(x2, row[i]);
                y2 = max(y2, col[j]);
            }
        }
    }
    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    t = t * 2 + 1;
    return (x2 - x1 + 1 <= t) && (y2 - y1 + 1 <= t);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
    }    
    int l = 0, r = max(n, m) + 1, ans = r, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (chk(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}