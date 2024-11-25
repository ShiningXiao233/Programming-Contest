#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;

int a[N];
int cnt[N];
int n;

int chk(int p) {
    int res = 0;
    for (int i = 1; i <= n; ++i) cnt[i] = 0;
    int l = p;
    for (int i = p; i <= n; i += 2) {
        if (a[i] != a[i + 1]) {
            for (int j = l; j < i; j += 2) cnt[a[j]] = 0;
            l = i + 2;
            continue;
        }
        cnt[a[i]] ++;
        while (l <= i && cnt[a[i]] > 1) {
            cnt[a[l]] --;
            l += 2;
        }
        res = max(res, i - l + 2);
    }
    return res;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << max(chk(1), chk(2)) << endl; 
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