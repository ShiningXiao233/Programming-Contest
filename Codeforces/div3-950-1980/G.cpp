#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;

class trie {

struct node
{
    node* ch[2];
    int val;
    node() : val(0) {ch[0] = ch[1] = nullptr;}
    ~node() {
        if (ch[0] != nullptr) delete ch[0];
        if (ch[1] != nullptr) delete ch[1];
    }
    node* to(int x) {
        if (x < 0 || x > 1) return nullptr;
        if (ch[x] == nullptr) ch[x] = new node();
        return ch[x];
    }
} *root;
static const int BIT = 30;

public:
    trie() : root(new node()) {}
    ~trie() {
        delete root;
    }
    void insert(int x, int val = 1) {
        node* p = root;
        p->val += val;
        for (int i = BIT; ~i; --i) {
            if ((x >> i) & 1) p = p->to(1);
            else p = p->to(0);
            p->val += val;
        }
    }
    int get_xor_max(int x) {
        int res = 0, t;
        node* p = root;
        if (root->val == 0) return -1;
        for (int i = BIT; ~i; --i) {
            t = ((x >> i & 1) ^ 1);
            // cout << t << ' ' << i << endl;
            if (p->ch[t] != nullptr && p->ch[t]->val > 0) {
                res |= (1 << i);
                p = p->ch[t];
                // cout << i << " --- " << endl;
            } else {
                p = p->ch[t ^ 1];
            }
        }
        return res;
    }
};

using Pair = pair<int, int>;

vector<Pair> G[N];
int W[N], c[N];

void dfs(int u = 1, int f = 0) {
    for (auto [v, w] : G[u]) {
        if (v == f) continue;
        W[v] = W[u] ^ w;
        c[v] = c[u] ^ 1;
        dfs(v, u);
    }
}

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    dfs(1);
    trie odd, even;
    int oddp = 0;

    for (int i = 1; i <= n; ++i) {
        // cout << i << " == " << W[i] << endl;
        if (c[i]) odd.insert(W[i]);
        else even.insert(W[i]);
    }
    char opt;
    int y, v, x;
    while (m --) {
        cin >> opt;
        if (opt == '^') {
            cin >> y;
            oddp ^= y;
        } else {
            cin >> v >> x;
            int TV = W[v] ^ x;
            // cout << TV << endl;
            if (c[v]) odd.insert(W[v], -1), TV ^= oddp;
            else even.insert(W[v], -1);
            // cout << "-- " << v << ' ' << TV << ' ' << even.get_xor_max(TV) << endl;
            // return;
            int ans = 0;
            ans = max(odd.get_xor_max(TV ^ oddp), even.get_xor_max(TV));

            cout << ans << ' ';
            if (c[v]) odd.insert(W[v]);
            else even.insert(W[v]);
        }
    }
    cout << '\n';
    for (int i =1; i <= n; ++i) G[i].clear();
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
        // break;
    }
}