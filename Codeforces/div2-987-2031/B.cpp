#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int i = 1;
    while (i <= n) {
        if (a[i] == i) {
            ++i;
            continue;
        }
        if (i == n) {
            cout << "NO\n";
            return;
        }
        if (a[i] == i + 1 && a[i + 1] == i) {
            i += 2;
            continue;
        }
        cout << "NO\n";
            return;
    }
    cout << "YES\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}