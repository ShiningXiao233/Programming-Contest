#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

class Matir {
public:
    Matir(ll x = 1) {
        memset(a, 0, sizeof(a));
        a[0][0] = a[1][1] = x;
    }

    Matir& operator = (ll v) {
        memset(a, 0, sizeof(a));
        a[0][0] = a[1][1] = v;
        return (*this);
    }

    void set(int x, int y, ll v) {
        a[x][y] = v; 
    }

    int get(int x, int y) const {
        return a[x][y];
    }
    
    void show() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << " ----- \n";
    }


    Matir operator + (const Matir& rhs) const {
        Matir res(0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res.a[i][j] = a[i][j] + rhs.a[i][j];
            }
        }
        return res;
    }

    Matir operator * (const Matir& rhs) const {
        Matir res(0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    res.a[i][j] += a[i][k] * rhs.a[k][j];
                }
            }
        }
        return res;
    }
    
private:
    ll a[2][2];
};

class str_tree {
public:
    str_tree(int n);

    void updata(int l, int r, const Matir& x) {
        _updata(l, r, x, 1, 1, N);
    }
    int query() {
        return _query(1, 1, N);
    }

    void show(int id, int l, int r); 
private:
    int _query(int id, int l, int r);
    void build(int id, int l, int r);
    void _updata(int L, int R, const Matir& x, int id, int l, int r);
    void push_down(int id);
    const int N;
    Matir *val;
    Matir *tag;
};


str_tree::str_tree(int n) : N(n) {
    val = new Matir[N * 4 + 1];
    tag = new Matir[N * 4 + 1];
    build(1, 1, N);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<ll> t, l, r, ST;
    ll xl, xr, xt;
    ST.push_back(1);
    for (int i = 1; i <= n; ++i) {
        cin >> xt >> xl >> xr;
        t.push_back(xt);
        l.push_back(xl);
        r.push_back(xr);
        ST.push_back(xl); 
        if (xl > 1) ST.push_back(xl - 1); 
        ST.push_back(xl + 1);
        ST.push_back(xr); 
        if (xr > 1) ST.push_back(xr - 1); 
        ST.push_back(xr + 1);
    }
    sort(ST.begin(), ST.end());
    ST.erase(unique(ST.begin(), ST.end()), ST.end());
    str_tree res(ST.size());
    Matir strt;
    ll now;
    for (int i = 0; i < n; ++i) {
        xt = t[i];
        xl = lower_bound(ST.begin(), ST.end(), l[i]) - ST.begin() + 1;
        xr = lower_bound(ST.begin(), ST.end(), r[i]) - ST.begin() + 1;
        strt = 0;
        if (xt == 1) {
            strt.set(1, 1, 1);
            strt.set(1, 0, 1);
            res.updata(xl, xr, strt);
        } else if (xt == 2) {
            strt.set(1, 1, 1);
            res.updata(xl, xr, strt);
        } else if (xt == 3) {
            strt.set(0, 0, -1);
            strt.set(1, 0, 1);
            strt.set(1, 1, 1);
            res.updata(xl, xr, strt);
        }
        now = res.query();
        cout << ST[now - 1] << '\n';
    }
    return 0;
}

void str_tree::show(int id, int l, int r) {
    if (l == r) {
        cout << "(" << l << ':' << val[id].get(0,0) << ')';
        return;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    show(id << 1, l, mid);
    show(id << 1 | 1, mid + 1, r);
    
}

int str_tree::_query(int id, int l, int r)
{
    if (l == r) {
        return l;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    if (val[id << 1].get(0, 0) != val[id << 1].get(0, 1)) {
        return _query(id << 1, l, mid);
    } else {
        return _query(id << 1 | 1, mid + 1, r);
    }
}

void str_tree::build(int id, int l, int r)
{
    // cout << l << ' ' << r << ' ' << ": \n";
    tag[id] = 1;
    if (l == r) {
        val[id] = 0;
        val[id].set(0, 1, 1);
        // val[id].show();
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    val[id] = val[id << 1] + val[id << 1 | 1];
        // val[id].show();

}

void str_tree::_updata(int L, int R, const Matir &x, int id, int l, int r)
{
    if (L > r || R < l) return;
    if (L <= l && r <= R) {
        tag[id] = tag[id] * x;
        val[id] = val[id] * x;
        return;
    }
    push_down(id);
    int mid = (l + r) >> 1;
    _updata(L, R, x, id << 1, l, mid);
    _updata(L, R, x, id << 1 | 1, mid + 1, r);
    val[id] = val[id << 1] + val[id << 1 | 1];
}

void str_tree::push_down(int id) {
    tag[id << 1] = tag[id << 1] * tag[id];
    tag[id << 1 | 1] = tag[id << 1 | 1] * tag[id];
    val[id << 1] = val[id << 1] * tag[id];
    val[id << 1 | 1] = val[id << 1 | 1] * tag[id];
    tag[id] = 1;
}
