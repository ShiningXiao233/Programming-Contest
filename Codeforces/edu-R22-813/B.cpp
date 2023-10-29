#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll x, y, l, r;

int main() {
    cin >> x >> y >> l >> r;
    vector<ll> ans{};

    ll tmp = 1;
    for (int i = 0; i < 60; ++i) {
        ll zg = 1;
        for (int j = 0; j < 60; ++j) {
            if (zg + tmp >= l)
                ans.push_back(zg + tmp);        
            if ((r - tmp) / zg < y) break;
            zg *= y;
        }
        if (r / tmp < x) break;
        tmp *= x;
    }
    ans.push_back(l - 1);
    ans.push_back(r + 1);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    ll tans = 0;
    for (int i = 1; i < ans.size(); ++i) {
        tans = max(tans, ans[i] - ans[i - 1] - 1);
    }
    cout << tans << endl;
    return 0;
}