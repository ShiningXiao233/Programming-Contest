#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    using Pair = pair<int, int>;
    vector<Pair> sg(n);
    vector<int> S;
    for (auto &x : sg) {
        cin >> x.first >> x.second;
        S.push_back(x.first);
        S.push_back(x.second);
        S.push_back(x.first - 1);
        S.push_back(x.second - 1);
        S.push_back(x.first + 1);
        S.push_back(x.second + 1);
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    vector<int> sum(S.size() + 3, 0), lst1_pos(S.size() + 3, -1);
    for (auto &x : sg) {
        x.first = lower_bound(S.begin(), S.end(), x.first) - S.begin();
        x.second = lower_bound(S.begin(), S.end(), x.second) - S.begin();
        sum[x.first] ++;
        sum[x.second + 1] --;
        // cout << x.first << ' ' << x.second << endl;
    }
    if (sum[0] == 1) lst1_pos[0] = 0;
    for (int i = 1; i < lst1_pos.size(); ++i) {
        sum[i] += sum[i - 1];
        if (sum[i] == 1) lst1_pos[i] = i;
        else lst1_pos[i] = lst1_pos[i - 1];
    }
    for (int i = 0; i < sg.size(); ++i) {
        auto [l, r] = sg[i];
        if (lst1_pos[r] < l) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}