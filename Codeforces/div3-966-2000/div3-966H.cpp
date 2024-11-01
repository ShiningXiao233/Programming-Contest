#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 4e6 + 100;
const int MOD = 998244353;
using ll = long long;

int MaxBlack[N << 2];
int rBlack[N << 2];
int lBlack[N << 2];

void push_up(int id, int ls, int rs) {
    int l = id << 1;
    int r = id << 1 | 1;
    MaxBlack[id] = max({MaxBlack[l], MaxBlack[r], rBlack[l] + lBlack[r]});
    rBlack[id] = rBlack[r] + (rBlack[r] == rs ? rBlack[l] : 0);
    lBlack[id] = lBlack[l] + (lBlack[l] == ls ? lBlack[r] : 0);
}

void init(int id = 1, int l = 1, int r = 4000000) {
    if (l == r) {
        MaxBlack[id] = rBlack[id] = lBlack[id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    init(id << 1, l, mid);
    init(id << 1 | 1, mid + 1, r);
    push_up(id, mid - l + 1, r - mid);
}

void update(int pos, int val, int id = 1, int l = 1, int r = 4000000) {
    if (l == r) {
        MaxBlack[id] = rBlack[id] = lBlack[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(pos, val, id << 1, l, mid);
    else update(pos, val, id << 1 | 1, mid + 1, r);
    push_up(id, mid - l + 1, r - mid);
}

int query(int k, int id = 1, int l = 1, int r = 4000000) {
    if (l == r) return l;
    if (MaxBlack[id] == r - l + 1) return l;
    int mid = (l + r) >> 1;
    if (MaxBlack[id << 1] >= k) return query(k, id << 1, l, mid);
    if (rBlack[id << 1] + lBlack[id << 1 | 1] >= k) {
        return mid - rBlack[id << 1] + 1;
    }
    return query(k, id << 1 | 1, mid + 1, r);
}
using Pair = pair<int, int>;

void sol() {
    int n, x;
    cin >> n;
    vector<Pair> opter;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        update(x, 0);
        opter.push_back({x, 1});
    }
    int m;
    cin >> m;
    char opt;
    while (m-- > 0) {
        cin >> opt >> x;
        if (opt == '+') {
            update(x, 0);
            opter.push_back({x, 1});
        } else if (opt == '-') {
            update(x, 1);
            // cout << x << "\n";
            // cout << query(2) << "\n";
            opter.push_back({x, 0});
        } else {
            cout << query(x) << ' ';
        }
        // return;
    }
    cout << '\n';
    reverse(opter.begin(), opter.end());
    for (auto [x, v] : opter) {
        update(x, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}