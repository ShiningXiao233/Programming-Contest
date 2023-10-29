#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

class str_tree {

public: 
    str_tree(int n, int t);
    ~str_tree();
    void update(int pos, int val) {
        _update(Time_root[TimeIdx - 1], Time_root[TimeIdx], pos, val, Lt, Rt);
        TimeIdx ++;
    }
    int query(int Tl, int Tr, int l, int r) const {
        if (r < l) return 0;
        return _query(Time_root[Tr], l, r, Lt, Rt) - _query(Time_root[Tl - 1], l, r, Lt, Rt);
    }
private:
    void _build(int &u, int l, int r);
    void _update(int oldT, int &newT, int pos, int v, int l, int r);
    int _query(int u, int tL, int tR, int l, int r) const;
    const int N, Time;
    int Lt, Rt;
    int Siv, TimeIdx;
    int cnt;
    int *val, *Time_root;
    int *L, *R;
};

const int N = 1e5+100;
int n, k;
int a[N], last = 0;
vector<int> pos[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < pos[i].size(); ++j) {
            if (j - k < 0) {
                a[pos[i][j]] = 0;
            } else {
                a[pos[i][j]] = pos[i][j - k];
            }
        }
    }
    str_tree ans(n + 2, n);
    for (int i = 1; i <= n; ++i) {
        ans.update(a[i], 1);
    }
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if (l > r) swap(l, r);
        cout << (last = ans.query(l, r, 0, l - 1)) << endl;
    }
    return 0;
}

str_tree::str_tree(int n, int t) : N(n), Time(t), cnt(0), TimeIdx(0), Lt(0), Rt(n - 1) {
    Siv = N * 4 + 1 + (log2(N) + 1) * (Time);
    val = new int[Siv];
    Time_root = new int[Time + 1];
    L = new int[Siv];
    R = new int[Siv];
    memset(L, -1, sizeof(int) * (Siv));
    memset(R, -1, sizeof(int) * (Siv));
    memset(Time_root, -1, sizeof(int) * (Time + 1));
    _build(Time_root[TimeIdx ++], Lt, Rt);
}

str_tree::~str_tree() {
    delete[] L;
    delete[] R;
    delete[] Time_root;
    delete[] val;
}

void str_tree::_build(int &u, int l, int r) {
    if (!(~u)) u = cnt ++;
    if (l == r) {
        val[u] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    _build(L[u], l, mid);
    _build(R[u], mid + 1, r);
    val[u] = val[L[u]] + val[R[u]];
}

void str_tree::_update(int oldT, int &newT, int pos, int v, int l, int r) {
    if (!(~newT)) newT = cnt ++;
    if (l == r) {
        val[newT] = val[oldT] + v;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        R[newT] = R[oldT];
        _update(L[oldT], L[newT], pos, v, l, mid);
    } else {
        L[newT] = L[oldT];
        _update(R[oldT], R[newT], pos, v, mid + 1, r);
    }
    val[newT] = val[L[newT]] + val[R[newT]];
}

int str_tree::_query(int u, int tL, int tR, int l, int r) const {
    if (tL > r || tR < l) return 0;
    if (tL <= l && r <= tR) return val[u];
    int mid = (l + r) >> 1;
    return _query(L[u], tL, tR, l, mid) + _query(R[u], tL, tR, mid + 1, r);
}
