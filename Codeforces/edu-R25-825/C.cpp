#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    typedef long long ll;
    ll k;
    cin >> n >> k;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (k * 2ll >= a[i]) {
            k = max(k, a[i] * 1ll);
        } else {
            while (k * 2ll < a[i]) {
                k *= 2ll;
                cnt ++;
            }
            k = max(k, a[i] * 1ll);
        }
    }
    cout << cnt << endl;
    return 0;
}