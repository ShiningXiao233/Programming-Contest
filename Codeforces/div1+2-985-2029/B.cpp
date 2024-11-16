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

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (auto c : s) {
        c == '1' ? ++cnt1 : ++cnt0;
    }
    cin >> s;
    for (auto c : s) {
        if (cnt0 == 0 || cnt1 == 0) {
            cout << "NO\n";
            return;
        }
        c == '0' ? --cnt1 : --cnt0;
    }
    if (cnt0 < 0 || cnt1 < 0) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
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