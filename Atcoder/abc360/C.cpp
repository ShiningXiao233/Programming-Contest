#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5+100;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> mp(n, vector<int>(0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i] --;
    }
    int x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ans += x;
        mp[a[i]].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (!mp[i].empty()) {
            sort(mp[i].begin(), mp[i].end(), [](int a, int b) -> bool {
                return a > b;
            });
            ans -= mp[i][0];
        }
    }
    cout << ans << endl;
    return 0;
}