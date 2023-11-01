#include <iostream>

using namespace std;
const int N = 1003;
int a[N], vis[N];
int l[N], n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> l[i];
    int pre = l[1];
    for (int i = 2; i <= m; ++i) {
        int now = l[i] - l[i - 1];
        if (now <= 0) now += n;
        if (a[pre] == 0) {
            if (vis[now]) {
                cout << -1 << endl;
                return 0;
            }
            a[pre] = now;
            vis[now] = 1;
        } else if (a[pre] != now) {
            cout << -1 << endl;
            return 0;
        }
        pre = l[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            int j = 1;
            while (vis[j]) {
                ++j;
            }
            a[i] = j;
            vis[j] = 1;
        }
        
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}