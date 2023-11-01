#include <iostream>
#include <cstring>
using namespace std;

class str_tree {

public:
    str_tree(int n) : N(n) {
        val = new int[N * 4 + 1];
        tag = new int[N * 4 + 1];
        memset(val, 0, sizeof(int) * (N * 4 + 1));
        memset(tag, 0, sizeof(int) * (N * 4 + 1));
    }
    ~str_tree() {
        delete[] val;
        delete[] tag;
    }

    int get_min() {
        return val[1];
    }
    void updata(int L, int R, int v) {
        _updata(L, R, v, 1, 1, N);
    }
private:

    void _updata(int L, int R, int v, int id, int l, int r) {
        if (L > r || R < l) return;
        if (L <= l && r <= R) {
            val[id] += v;
            tag[id] += v;
            return;
        } 
        push_down(id);
        int mid = (l + r) >> 1;
        _updata(L, R, v, id << 1, l, mid);
        _updata(L, R, v, id << 1 | 1, mid + 1, r);
        push_up(id);
    }

    void push_down(int id) {
        if (tag[id] != 0) {
            val[id << 1] += tag[id];
            val[id << 1 | 1] += tag[id];
            tag[id << 1] += tag[id];
            tag[id << 1 | 1] += tag[id];
            tag[id] = 0;
        }
    }
    void push_up(int id) {
        val[id] = min(val[id << 1], val[id << 1 | 1]);
    }
    const int N;
    int *val, *tag;

};

const int N = 1e6+10;

#include <vector>
#include <stack>
int n, A;

vector<int> pos[N];

int main() {
    cin >> n >> A;
    int c;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        pos[c].push_back(i);
    }
    str_tree res(n);
    for (int x : pos[A]) {
        res.updata(x, n, -1);
    }
    for (int i = 1; i < N; ++i) {
        if (i == A) continue;
        for (int x : pos[i]) {
            res.updata(x, n, 1);
        }
        if (res.get_min() >= 0) {
            cout << i << endl;
            return 0;
        }
        for (int x : pos[i]) {
            res.updata(x, n, -1);
        }
    }
    cout << -1 << endl;
    return 0;
}