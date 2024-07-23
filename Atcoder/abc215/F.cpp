#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5+100;

using Pair = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<Pair> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first >> s[i].second;
    }    
    sort(s.begin(), s.end());
    vector<int> preMax(n), preMin(n), sufMax(n), sufMin(n);
    preMax[0] = preMin[0] = s[0].second;
    sufMax[n - 1] = sufMin[n - 1] = s[n - 1].second;
    for (int i = 1; i < n; ++i) {
        preMax[i] = max(preMax[i - 1], s[i].second);
        preMin[i] = min(preMin[i - 1], s[i].second);
    }
    for (int i = n - 2; i >= 0; --i) {
        sufMax[i] = max(sufMax[i + 1], s[i].second);
        sufMin[i] = min(sufMin[i + 1], s[i].second);
    }
    auto chk = [&](int pos, int x) -> bool {
        int p1 = lower_bound(s.begin(), s.end(), make_pair(s[pos].first + x, -1)) - s.begin();
        int xx = 0;
        if (p1 < n) {
            xx = max(abs(sufMax[p1] - s[pos].second), xx);
            xx = max(abs(sufMin[p1] - s[pos].second), xx);
        }
        p1 = upper_bound(s.begin(), s.end(), make_pair(s[pos].first - x, static_cast<int>(2e9))) - s.begin() - 1;
        if (p1 >= 0) {
            xx = max(abs(preMax[p1] - s[pos].second), xx);
            xx = max(abs(preMin[p1] - s[pos].second), xx);
        }
        return xx >= x;
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = ans, r = 1e9, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (chk(i, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
    }
    cout << ans << endl;
    return 0;
}