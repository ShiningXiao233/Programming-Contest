#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

using ll = long long;

struct node
{
    node* lson;
    node* rson;
    int MaxBlack,rBlack,lBlack;
    int l, r;
    int len;
    node(int _l, int _r) : l(_l), r(_r), len(_r - _l + 1), 
    MaxBlack(_r - _l + 1), rBlack(_r - _l + 1), lBlack(_r - _l + 1), lson(nullptr), rson(nullptr) {}

    node(int _l, int _r, int M, int lM, int rM) : l(_l), r(_r), len(_r - _l + 1),
    MaxBlack(M), rBlack(rM), lBlack(lM), lson(nullptr), rson(nullptr) {}

    void merge_son() {
        MaxBlack = max({lson->MaxBlack, rson->MaxBlack, lson->rBlack + rson->lBlack});
        rBlack = rson->rBlack + (rson->rBlack == rson->len ? lson->rBlack : 0); 
        lBlack = lson->lBlack + (lson->lBlack == lson->len ? rson->lBlack : 0); 
    }
    void update(int pos, int val) {
        if (l == r) {
            MaxBlack = rBlack = lBlack = val;
            return;
        }

        int mid = (l + r) >> 1;
        if (lson == nullptr) {
            lson = new node(l, mid);
            rson = new node(mid + 1, r);
        }
        if (pos <= mid) lson->update(pos, val);
        else rson->update(pos, val);
        merge_son();
    }
    int query(int k) {
        if (MaxBlack == len) return l;
        if (lson->MaxBlack >= k) return lson->query(k);
        if (lson->rBlack + rson->lBlack >= k) {
            return lson->r - lson->rBlack + 1;
        }
        return rson->query(k);
    }
};

node *res = new node(1, 4000000);

using Pair = pair<int, int>;

void sol() {
    int n, x;
    cin >> n;
    vector<Pair> opter;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        res->update(x, 0);
        opter.push_back({x, 1});
    }
    int m;
    cin >> m;
    char opt;
    while (m-- > 0) {
        cin >> opt >> x;
        if (opt == '+') {
            res->update(x, 0);
            opter.push_back({x, 1});
        } else if (opt == '-') {
            res->update(x, 1);
            // cout << x << "\n";
            // cout << query(2) << "\n";
            opter.push_back({x, 0});
        } else {
            cout << res->query(x) << ' ';
        }
        // return;
    }
    cout << '\n';
    reverse(opter.begin(), opter.end());
    for (auto [x, v] : opter) {
        res->update(x, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // break;
    }
}