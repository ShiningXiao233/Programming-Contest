#include <iostream>
#include <iomanip>

using namespace std;
typedef long long ll;
int n, k;
const int N = 2e5+100;
ll a[N];
int main() {
    cin >> n >> k;
    long long res = 0, x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }    
    for (int i = k; i <= n; ++i) {
        res += a[i] - a[i - k];
    }
    cout << fixed << setprecision(10) << static_cast<double>(res) / static_cast<double>(n - k + 1) << endl;
    return 0;
}