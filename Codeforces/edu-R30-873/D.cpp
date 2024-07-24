#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
int a[N];
int n, k;

void mg(int l, int r) {
    if (k <= 0) return;
    if (l + 1 == r) return;
    k -= 2;
    int mid = (l + r) / 2;
    swap(a[mid - 1], a[mid]);
    mg(l, mid);
    mg(mid, r);
}

void sol() {
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    k --;
    mg(0, n);
    if (k != 0) cout << -1 << '\n';
    else {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }

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