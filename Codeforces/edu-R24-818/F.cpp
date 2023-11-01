#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll F(int n, int x) {
    return n - x + min(1ll * (n - x), 1ll * x * (x - 1) / 2);
}

void sol() {
    int n;
    cin >> n;
    ll l = 1, r = n, mid1, mid2, ans = 0, f1, f2;
    while (l < r - 1) {
        mid1 = (l + r) >> 1;
        mid2 = (mid1 + r) >> 1;
        f1 = F(n, mid1);
        f2 = F(n, mid2);
        ans = max({ans, f1, f2});
        if (f1 < f2) l = mid1;
        else r = mid2;
    }
    cout << max({1ll * ans, F(n, l), F(n, r)}) << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) sol();    
    return 0;
}