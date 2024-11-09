/*

很难描述清楚。
写起来也很费劲，情况也很多。

基本的思路是定义关键点，关键点的定义和设计很关键，然后是一种类似于扫描线的思路。

然后去除关键点后，对前后两个关键点之间重新扫描，由于每个点不会超过两次，整体点复杂度为 O(n)。

关键在于如何定义关键点，是按照行，还是列，如果是其他思路点话，很难写。

 */

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

int n, m;
int k;
struct node {
    int x, y, id;
    bool operator < (const node& rhs) const {
        if (y != rhs.y) return y < rhs.y;
        return x > rhs.x;
    }
}s[N];
bool vis[N];
ll ans[N];
void sol() {
    cin >> n >> m >> k;
    s[0].x = 0;
    s[0].y = 1;
    s[0].id = 0;
    s[k + 1].x = n;
    s[k + 1].y = m + 1;
    s[k + 1].id = k + 1;
    for (int i = 1; i <= k; ++i) {
        s[i].id = i;
        cin >> s[i].x >> s[i].y;
    }
    for (int i = 0; i <= k + 1; ++i) {
        vis[i] = false;
    }
    vis[0] = true;
    sort(s + 1, s + k + 2);
    ll res = 0;
    int x = 0, y = 1;
    for (int i = 1; i <= k + 1; ++i) {
        if (s[i].x < x) continue;
        res += 1ll * (n - x) * (s[i].y - y);
        x = s[i].x;
        y = s[i].y;
        vis[i] = true;
    }
    for (int i = 1; i <= k; ++i) {
        if (!vis[i]) {ans[s[i].id] = 0; continue;}
        int l = i - 1;
        int r = i + 1;
        while (!vis[l]) --l;
        while (!vis[r]) ++r;
        ll pre = 0, tmp = 0;
        pre = 1ll * (n - s[l].x) * (s[i].y - s[l].y);
        pre += 1ll * (n - s[i].x) * (s[r].y - s[i].y);
        int j = i + 1, x = s[l].x, y = s[l].y;
        for (; j <= r; ++j) {
            if (s[j].x < x) continue;
            tmp += 1ll * (n - x) * (s[j].y - y);
            x = s[j].x;
            y = s[j].y;
        }
        ans[s[i].id] = tmp - pre;
    }
    cout << res << '\n';
    for (int i = 1; i <= k; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // break;
    }
}