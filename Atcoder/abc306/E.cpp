#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 5e5+100;
const int MOD = 998244353;
int n, k, q;

vector<int> ST;
int X[N], Y[N];
int val[N];
ll sum[N];
ll num[N];

#define lowbit(x) (x) & (-(x))


void upd(ll *f, int pos, int val) {
    while (pos < N) {
        f[pos] += val;
        pos += lowbit(pos);
    }
}

ll get(ll* f, int pos) {
    ll sum = 0;
    while (pos > 0)  {
        sum += f[pos];
        pos -= lowbit(pos);
    }
    return sum;
}

ll getans(int g) {
    int l = 1, r = N - 1, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (get(num, mid) >= g) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return get(sum, ans) - 1ll * ST[ans] * (get(num, ans) - g);
}

void sol() {
    cin >> n >> k >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> X[i] >> Y[i];
        ST.push_back(Y[i]);
    }
    ST.push_back(-1);
    ST.push_back(0);
    sort(ST.begin(), ST.end());
    ST.erase(unique(ST.begin(), ST.end()), ST.end());
    int idx = lower_bound(ST.begin(), ST.end(), 0) - ST.begin();
    upd(num, idx, n);

    for (int i = 1; i <= q; ++i) {
        Y[i] = lower_bound(ST.begin(), ST.end(), Y[i]) - ST.begin();
        idx = lower_bound(ST.begin(), ST.end(), val[X[i]]) - ST.begin();
        upd(num, idx, -1);
        upd(num, Y[i], 1);
        upd(sum, idx, -ST[idx]);
        upd(sum, Y[i], ST[Y[i]]);
        val[X[i]] = ST[Y[i]];
        cout << get(sum, N - 1) - getans(n - k) << '\n';
    }
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