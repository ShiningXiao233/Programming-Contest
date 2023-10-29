#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

class DSU {
public:
    DSU(int n);
    ~DSU();
    bool add(int a, int b, stack<pair<int,int>> &st) {
        if (_top(a) != _top(b)) {
            int tp = 1 ^ _len(a) ^ _len(b);
            a = _top(a);
            b = _top(b);
            if (_siv[a] < _siv[b]) {
                swap(a, b);
            }
            st.push(make_pair(a, b));
            _fa[b] = a;
            _dep[b] = tp;
            _siv[a] += _siv[b];
        } else {
            a = _len(a) ^ _len(b);
            if (!a) return false;
            else {
                return true;
            }
        }
        return true;
    }

    void to_back(int a, int b) {
        _siv[a] -= _siv[b];
        _dep[b] = 0;
        _fa[b] = b;
    }

private:
    int _len(int);
    int _top(int);
    const int N;
    int *_siv, *_fa, *_dep;
};

class str_tree {

public:
    str_tree(int n);
    ~str_tree();
    void updata(int L, int R, int a, int b) {
        _updata(L, R, a, b, 1, 1, N);
    }
    void run(int n) {
        DSU dsu(n + 1);
        _find(1, 1, N, true, dsu);
    }
private:
    void _updata(int L, int R, int a, int b, int id, int l, int r);
    void _find(int id, int l, int r, bool ok, DSU& res);
    const int N;
    vector<pair<int, int>> *node;
};

map<pair<int, int>,int> tp;

int main() {
    int n, q, x, y, l, r;
    cin >> n >> q;
    str_tree sol(q);

    for (int i = 1; i <= q; ++i) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (tp[make_pair(x, y)] != 0) {
            l = tp[make_pair(x, y)];
            r = i - 1;
            sol.updata(l, r, x, y);
            tp[make_pair(x, y)] = 0;
        } else {
            tp[make_pair(x, y)] = i;
        }
    }
    for (auto &it : tp) {
        if (it.second != 0) {
            sol.updata(it.second, q, it.first.first, it.first.second);
        }
    }
    sol.run(n);
    return 0;
}

DSU::DSU(int n) : N(n) {
    _siv = new int[N];
    _fa = new int[N];
    _dep = new int[N];
    for (int i = 0; i < N; ++i) {
        _siv[i] = 1;
        _fa[i] = i;
        _dep[i] = 0;
    }
}

DSU::~DSU() {
    delete[] _fa;
    delete[] _siv;
    delete[] _dep;
}

int DSU::_len(int x) {
    if (x == _fa[x]) return _dep[x];
    return _dep[x] ^ _len(_fa[x]);
}

int DSU::_top(int x)
{
    if (x == _fa[x]) return x;
    else return _top(_fa[x]);
}

str_tree::str_tree(int n) : N(n) {
    node = new vector<pair<int,int>>[(N + 1) * 4 + 1];
}

void str_tree::_updata(int L, int R, int a, int b, int id, int l, int r) {
    if (L > r || R < l) return;
    if (L <= l && r <= R) {
        node[id].push_back({a, b});
        return;
    }
    int mid = (l + r) >> 1;
    _updata(L, R, a, b, id << 1, l, mid);
    _updata(L, R, a, b, id << 1 | 1, mid + 1, r);
}

void str_tree::_find(int id, int l, int r, bool ok, DSU& res) {
    
    if (ok) {
        stack<pair<int,int> > fp{};
        for (pair<int, int> &x : node[id]) {
            if (!res.add(x.first, x.second, fp)) {
                ok = false;
                break;
            }
        }

        if (l == r) {
            cout << (ok ? "YES\n" : "NO\n");
            while (!fp.empty()) {
                res.to_back(fp.top().first, fp.top().second);
                fp.pop();
            }
            return;
        }

        int mid = (l + r) >> 1;
        _find(id << 1, l, mid, ok, res);
        _find(id << 1 | 1, mid + 1, r, ok, res);
        
        while (!fp.empty()) {
            res.to_back(fp.top().first, fp.top().second);
            fp.pop();
        }
    } else {
        if (l == r) {
            cout << "NO\n";
            return;
        }
        int mid = (l + r) >> 1;
        _find(id << 1, l, mid, ok, res);
        _find(id << 1 | 1, mid + 1, r, ok, res);
    }
} 

str_tree::~str_tree() {
    delete[] node;
}