#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 2e6+100;
const int MOD = 998244353;

struct etree
{
    int h, w, d;
    /* data */
}s[N];
int cnt = 0;
int n;
int ans = 0;

vector<int> ST;

bool cmp1(const etree& a, const etree& b) {
    return a.h < b.h;
}
const int NN = 600010;
int gg[NN];

#define lowbit(x) (x&-x)

void update(int pos, int val) {
    while (pos < NN) {
        gg[pos] = min(gg[pos], val);
        pos += lowbit(pos);
    }
}

bool get(int a, int b) {
    while (a > 0) {
        if (gg[a] <= b) return 1;
        a -= lowbit(a);
    }
    return 0;
}

bool chk() {
    int pre = 1;
    for (int i = 1; i <= cnt; ++i) {
        if (s[i].h != s[i - 1].h) {
            for (int j = pre; j < i; ++j) {
                update(s[j].w, s[j].d);
            }
            pre = i;
        }
        if (get(s[i].w - 1, s[i].d - 1)) {
            return 1;
        }
    }
    return 0;
}

void sol() {
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> c;
        s[++cnt] = {a, b, c};
        s[++cnt] = {a, c, b};
        s[++cnt] = {b, a, c};
        s[++cnt] = {b, c, a};
        s[++cnt] = {c, a, b};
        s[++cnt] = {c, b, a};
        ST.push_back(a);
        ST.push_back(b);
        ST.push_back(c);
    }
    memset(gg, 0x3f, sizeof(gg));
    ST.push_back(0);
    sort(ST.begin(), ST.end());
    ST.erase(unique(ST.begin(), ST.end()), ST.end());
    for (int i = 1; i <= cnt; ++i) {
        s[i].h = lower_bound(ST.begin(), ST.end(), s[i].h) - ST.begin();
        s[i].w = lower_bound(ST.begin(), ST.end(), s[i].w) - ST.begin();
        s[i].d = lower_bound(ST.begin(), ST.end(), s[i].d) - ST.begin();
    }
    sort(s + 1, s + cnt + 1, cmp1);
    cout << (chk() ? "Yes" : "No") << '\n';
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
}