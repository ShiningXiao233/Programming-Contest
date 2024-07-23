#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1e5+100;

int main() {
    int n, t;
    string s;
    cin >> n >> t >> s;
    int x;
    vector<int> s1, s0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (s[i] == '0') s0.push_back(x);
        else s1.push_back(x);
    }
    sort(s0.begin(), s0.end());
    sort(s1.begin(), s1.end());
    long long ans = 0;
    for (int v : s1) {
        ans += upper_bound(s0.begin(), s0.end(), v + 2ll * t) - upper_bound(s0.begin(), s0.end(), v);
    }
    cout << ans << '\n';
    return 0;
}