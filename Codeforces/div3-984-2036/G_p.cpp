/**
 * jangly的思路
 * 将其分为[l,m), [m, r)
 * 保证 [m, r)的最高位一致都是1，同样的[l,m)最高位为0
 * 如果[m,r)出现某些整数，那么它的异或和肯定不会为0，所以可以直接得到值在该区间。否则在另外的区间
 * 次数计算，总共的位数为60位，每一位计算两次，所以最多查询120次
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
using ll = int64_t;

vector<ll> ans;
ll n;
ll ask(ll l, ll r) {   
    l = max<ll>(l, 1);
    r = min<ll>(r - 1, n);
    if (l > r) return 0;
    printf("xor %lld %lld\n", l, r);
    fflush(stdout);
    ll x;
    scanf("%lld", &x);
    return x;
}


void sol() {
    ans.clear();
    cin >> n;
    ll l = 0, r = (1ll << 60), d = 60;
    while (1) {
        ll mid = (l + r) / 2;
        auto a = ask(l, mid);
        auto b = ask(mid, r);
        d --; // 当前 [mid, r) 的最高位
        if (b == 0) r = mid;
        else if (a == 0) l = mid;
        else {
            if (b >> d & 1) {
                ans.push_back(b);
                r = mid;
                break;
            } else {
                ans.push_back(a);
                l = mid;
                break;
            }
        }
    }
    while (1) {
        ll mid = (l + r) / 2;
        auto a = ask(l, mid);
        auto b = ask(mid, r);
        if (b == 0) {
            r = mid;    
        } else if (a == 0) {
            l = mid;
        } else {
            ans.push_back(a);
            ans.push_back(b);
            break;
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