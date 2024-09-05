#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;
using ll = long long;
const int N = 1e6 + 100;
const int MOD = 998244353;
int f[N];
struct node
{
    ll val;
    bool flag;
} s[N << 2];

void build(int id, int begin, int end) {
    if (begin == end) {
        // cout << begin << endl;
        cin >> s[id].val;
        s[id].flag = (s[id].val <= 2);
        return;
    }
    int mid = (begin + end) / 2;
    build(id << 1, begin, mid);
    build(id << 1 | 1, mid + 1, end);
    s[id].val = s[id << 1].val + s[id << 1 | 1].val;
    s[id].flag = s[id << 1].flag & s[id << 1 | 1].flag;
}

void update(int l, int r, int id, int begin, int end) {
    if (l > end || r < begin) return;
    if (s[id].flag) return;
    if (begin == end) {
        s[id].val = f[s[id].val];
        s[id].flag = (s[id].val <= 2);
        return;
    }
    int mid = (begin + end) / 2;
    update(l, r, id << 1, begin, mid);
    update(l, r, id << 1 | 1, mid + 1, end);
    s[id].val = s[id << 1].val + s[id << 1 | 1].val;
    s[id].flag = s[id << 1].flag & s[id << 1 | 1].flag;
}

ll query(int l, int r, int id, int begin, int end) {
    if (l > end || r < begin) return 0;
    if (l <= begin && end <= r) return s[id].val;
    int mid = (begin + end) / 2;
    return query(l, r, id << 1, begin, mid) +
    query(l, r, id << 1 | 1, mid + 1, end);
}

void sol() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            f[j] ++;
        }
    }    
    int n, m;
    cin >> n >> m;
    // cout << " ---- " << endl;
    build(1, 1, n);
    int opt, l, r;
    while (m --) {
        cin >> opt >> l >> r;
        if (opt == 1) {
            update(l, r, 1, 1, n);
        } else {
            cout << query(l, r, 1, 1, n) << '\n';
        }
    }
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
}