#include <iostream>

using namespace std;



int main() {
    int n, w;
    cin >> n >> w;
    int *a = new int[n + 2], *p = new int[n + 2];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = (a[i] + 1) / 2;
        w -= p[i];
    }
    a[0] = p[0] = 0;
    if (w < 0) {
        cout << -1 << endl;
        exit(0);
    } else {
        int j = 0;
        while (w > 0) {
            for (int i = 1; i <= n; ++i) {
                if ((a[i] - p[i] > a[j] - p[j]) || (a[i] - p[i] == a[j] - p[j] && a[i] > a[j])) {
                    j = i;
                }
            }
            int tmp = min(w, a[j] - p[j]);
            w -= tmp;
            p[j] += tmp;
        }
        for (int i = 1; i <= n; ++i) {
            cout << p[i] << ' ';
        }
    }
    delete[] a, p;
    
    return 0;
}