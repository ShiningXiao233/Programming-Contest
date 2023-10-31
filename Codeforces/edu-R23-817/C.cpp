#include <iostream>

using namespace std;

typedef long long ll;

bool chk(ll x, ll s){
    ll res = 0, t = x;
    while (t > 0) {
        res += t % 10;
        t /= 10;
    }
    return x - res >= s;
}

int main() {
    ll n, s;
    cin >> n >> s;
    ll r = min(s + 200, n);
    ll ans = n - r;
    for (ll i = s; i <= r; ++i) {
        if (chk(i, s)) ans ++;
    }     
    cout << ans << '\n';
    return 0;
}