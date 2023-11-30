#include <iostream>
#include <algorithm>

using namespace std;

int a[103], b[103], n;
int x, y;

int get(int a1, int b1, int a2, int b2) {
    int res = a1 * b1 + a2 * b2;
    a1 = max(a1, a2);
    b1 += b2;
    return ((x >= a1 && y >= b1) || (y >= a1 && x >= b1)) ? res : 0;
}

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ans = max({ans, get(a[i], b[i], a[j], b[j]), 
                    get(a[i], b[i], b[j], a[j]),
                    get(b[i], a[i], a[j], b[j]), 
                    get(b[i], a[i], b[j], a[j])});
        }
    }    
    cout << ans << endl;
    return 0;
}