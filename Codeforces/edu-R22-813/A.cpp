#include <iostream>

using namespace std;

const int N = 1e3+100;

int n, m;
int a[N], L[N], R[N];

int main() {
    cin >> n;
    int st = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], st += a[i];
    int ans = -1;
    cin >> m;
    
    for (int i = 0; i < m; ++i) {
        cin >> L[i] >> R[i];
        if (L[i] <= st && R[i] >= st || L[i] >= st) {
            ans = max(L[i], st);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}