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
int n, m, q;
ll a[N], b[N];
using Pair = pair<int, int>;

vector<Pair> gp[N];

struct segtr {

ll *val;
ll *tag;
int n;
segtr(int _n, ll *a) : n(_n) {
    val = new ll[n * 4 + 2];
    tag = new ll[n * 4 + 2];
    build(1, 1, n, a);
}

void build(int id, int l, int r, ll *a) {
    tag[id] = 0;
    if (l == r) {
        val[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid, a);
    build(id << 1 | 1, mid + 1, r, a);
    val[id] = min(val[id << 1], val[id << 1 | 1]);
}

void push_down(int id) {
    if (tag[id]) {
        tag[id << 1] += tag[id];
        tag[id << 1 | 1] += tag[id];
        val[id << 1] += tag[id];
        val[id << 1 | 1] += tag[id];
        tag[id] = 0;
    }
}

void upd(int L, int R, int tg, int id, int l, int r) {
    if (L > r || R < l) return;
    if (L <= l && r <= R) {
        tag[id] += tg;
        val[id] += tg;
        return;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    upd(L, R, tg, id << 1, l, mid); 
    upd(L, R, tg, id << 1 | 1, mid + 1, r);
    val[id] = min(val[id << 1], val[id << 1 | 1]);
}

ll query(int L, int R, int id, int l, int r) {
    if (L > r || R < l) return static_cast<ll>(1e18);
    if (L <= l && r <= R) {
        return val[id];
    }
    push_down(id);
    int mid = (l + r) >> 1;
    return min(query(L, R, id << 1, l, mid),
               query(L, R, id << 1 | 1, mid + 1, r));
}

void show(int id, int l, int r) {
    if (l == r) {
        if (l == 1) {
            cout << " -- ";
        }
        cout << val[id] << ' ';
        if (l == n) {
            cout << "\n";
        }
        
        return;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    show(id << 1, l, mid);
    show(id << 1 | 1, mid + 1, r);
}

};

ll tmp_a[N];


void sol() {
    cin >> n >> m >> q;
    for (int i = 2; i <= n; ++i) {
        cin >> a[i - 1] >> b[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        gp[x].push_back(make_pair(y, z));
    }
    segtr tree_b(n, b);
    for (int i = 1; i <= n; ++i) {
        for (auto [y, z] : gp[i]) {
            tree_b.upd(1, y, z, 1, 1, n);
        }
        // tree_b.show(1, 1, n);
        tmp_a[i] = a[i] + tree_b.query(1, n, 1, 1, n);
    }
    // tmp_a[1] = static_cast<ll>(1e18);
    segtr tree_a(n, tmp_a);
    cout << tree_a.query(1, n, 1, 1, n) << '\n';
    while (q --) {
        int x, z;
        cin >> x >> z;
        tree_a.upd(x, x, z - a[x], 1, 1, n);
        a[x] = z;
        cout << tree_a.query(1, n, 1, 1, n) << '\n';
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
    exit(0);
}