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
const int TBit = 29;
int ch[N * 30][2], L[N * 30], R[N * 30];
int root = 1, idx = 1;
vector<int> a;
int n;

void insert(int& p, int x, int bit, int id) {
    if (p == 0) p = ++idx, L[p] = id;
    R[p] = id;
    if (bit < 0) return;
    int nbit = ((x >> bit) & 1);
    insert(ch[p][nbit], x, bit - 1, id);
}
ll ans = 0;

int get_bit(int p, int x, int Bit) {
    int res = 0;
    for (int i = Bit; i >= 0; --i) {
        int bx = x >> i & 1;
        if (ch[p][bx]) {
            p = ch[p][bx];
        } else {
            res |= (1 << i);
            p = ch[p][bx ^ 1];
        }
    }
    return res;
}

void get_ans(int p, int bit) {
    if (p == 0 || bit < 0) return;
    if (ch[p][0] && ch[p][1]) {
        int Si0 = R[ch[p][0]] - L[ch[p][0]] + 1;
        int Si1 = R[ch[p][1]] - L[ch[p][1]] + 1;
        int tmp = 1e9;
        if (Si0 < Si1) {
            for (int i = L[ch[p][0]]; i <= R[ch[p][0]]; ++i) {
                tmp = min(tmp, (1 << bit) | get_bit(ch[p][1], a[i], bit - 1));                
            }
        } else {
            for (int i = L[ch[p][1]]; i <= R[ch[p][1]]; ++i) {
                tmp = min(tmp, (1 << bit) | get_bit(ch[p][0], a[i], bit - 1));
            }
        }
        ans += tmp;
    }
    get_ans(ch[p][0], bit - 1);
    get_ans(ch[p][1], bit - 1);
}

void sol() {
    cin >> n;
    a.resize(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        insert(root, a[i], TBit, i);
    }
    get_ans(root, TBit);
    cout << ans << '\n';

}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}