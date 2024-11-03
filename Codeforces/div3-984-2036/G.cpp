/**
 * 简单二分
 * 但是存在次数超出的问题
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;

vector<ll> ans;

bool ask(ll l, ll r) {
    printf("xor %lld %lld\n", l, r);
    fflush(stdout);
    ll x;
    scanf("%lld", &x);
    return x != 0ll;
}

void to_get(ll l, ll r) {
    if (l > r) return;
    if (l == r) {
        ans.push_back(l);
        return;
    }
    ll mid = (l + r) / 2;
    if (ask(l, mid)) {
        to_get(l, mid);
    }

    if (ans.size() < 3 && ask(mid + 1, r)) {
        to_get(mid + 1, r);
    }
}

void sol() {
    ll n;
    cin >> n;
    ans.clear();
    ll r = 1;
    for (ll i = 1; i <= n; i *= 2) {
        if (ask(r, i)) {
            to_get(r, i);
            if (ans.size() < 3)
                to_get(i + 1, n);
            break;
        } else {
            r = i + 1;
        }
        if (i * 2 > n) {
            to_get(i + 1, n);
        }
    }
    printf("ans %lld %lld %lld\n", ans[0], ans[1], ans[2]);
    fflush(stdout);
}

int main() {
    int T = 1;
    scanf("%d", &T);
    while (T--) {
        sol();
    }
}