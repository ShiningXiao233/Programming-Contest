#include <iostream>
#include <cstring>

using namespace std;

class dir_tree {

public:
    dir_tree(int _n);
    ~dir_tree();
    void insert(int n, int vv) {
        int p = ST, v;
        for (int i = 31; i >= 0; --i) {
            v = (n >> i) & 1;
            val[p] += vv;
            if (to[v][p] == -1) {
                val[idx] = 0;
                to[v][p] = idx++;
            }
            p = to[v][p];
        }
        val[p] += vv;
    }
    int get(int n, int l);
private:
    int idx, ST;
    int *to[2];
    int *val;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, opt, p, l;
    cin >> n;
    dir_tree res(n * 32 + 2);
    while (n--) {
        cin >> opt;
        switch (opt) {
            case 1:
                cin >> p;
                res.insert(p, 1);
                break;
            case 2:
                cin >> p;
                res.insert(p, -1);
                break;
            case 3:
                cin >> p >> l;
                cout << res.get(p, l) << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

dir_tree::dir_tree(int _n) : idx(1), ST(0) {
    val = new int[_n];
    val[ST] = 0;
    to[0] = new int[_n];
    to[1] = new int[_n];
    memset(to[0], -1, sizeof(int) * _n);
    memset(to[1], -1, sizeof(int) * _n);
}

dir_tree::~dir_tree() {
    delete[] val;
    delete[] to[0];
    delete[] to[1];
}

int dir_tree::get(int n, int l) {
    int p = ST, res = 0;
    for (int i = 31; i >= 0; --i) {
        if (p == -1) break;
        int v1 = (n >> i) & 1;
        int v2 = (l >> i) & 1;
        if (v2 == 1) {
            if (to[v1][p] != -1) {
                res += val[to[v1][p]];
            }
            p = to[v1 ^ 1][p];
        } else {
            p = to[v1][p];
        }
    }
    return res;
}
