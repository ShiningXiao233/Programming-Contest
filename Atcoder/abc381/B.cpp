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

string chk(string& x) {
    vector<int> cnt(255, 0);
    if (x.length() % 2) return "No";
    for (int i = 1; i + i <= x.length(); ++i) {
        if (x[i * 2 - 1 - 1] != x[i * 2 - 1]) {
            return "No";
        }
    }
    for (char c : x) {
        cnt[c] ++;
    }
    for (int c : cnt) {
        if (c != 0 && c != 2) return "No";
    }
    return "Yes";
}

void sol() {
    string S;
    cin >> S;
    cout << chk(S) << '\n';
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
}