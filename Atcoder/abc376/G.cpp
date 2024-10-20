#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
const int MOD = 998244353;
int n;
int p[N], a[N], fa[N];

struct node_t {
    int cnt0, cnt1, id;
    node_t(int a = 0, int b = 0, int i = 0) : cnt0(a), cnt1(b), id(i) {};
    node_t& operator += (const node_t& other) {
        cnt0 += other.cnt0;
        cnt1 += other.cnt1;
        return (*this);
    }
    friend bool operator < (const node_t& x, const node_t& other) {
        return 1ll * x.cnt0 * other.cnt1 < 1ll * x.cnt1 * other.cnt0;
    }
    friend bool operator > (const node_t& x,const node_t& other) {
        return 1ll * x.cnt0 * other.cnt1 > 1ll * x.cnt1 * other.cnt0;
    }
    bool operator != (const node_t& other) {
        return cnt0 != other.cnt0 || cnt1 != other.cnt1;
    }
} nt[N];

int father(int x) {
    return x == fa[x] ? x : fa[x] = father(fa[x]);
}

int qp(int x, int p = MOD - 2) {
    int res = 1;
    while (p) {
        if (p & 1) res = 1ll * res * x % MOD;
        p >>= 1;
        x = 1ll * x * x % MOD;
    }
    return res;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    int sum = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    priority_queue<node_t> q;

    for (int i = 0; i <= n; ++i) {
        nt[i] = node_t(a[i], 1, i);
        fa[i] = i;
        if (i) q.push(nt[i]);
    }
    ll ans = 0;
    while (!q.empty()) {
        auto u = q.top(); q.pop();
        if (u != nt[u.id]) continue;
        int fu = father(u.id), fp = father(p[u.id]);
        ans += 1ll * nt[fu].cnt0 * nt[fp].cnt1 % MOD;
        // cout << u.id << ' ' << nt[fu].cnt0 << ' ' << 1 << endl;
        ans %= MOD;
        fa[fu] = fp;
        nt[fp] += nt[fu];
        if (fp) q.push(nt[fp]);
    }
    cout << 1ll * ans * qp(sum) % MOD << endl;
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
    exit(0);
}