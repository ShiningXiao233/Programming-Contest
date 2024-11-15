#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
const int N = 2e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 10, 0);
    if (n % 2 == 0) {
        int cnt = 0;
        for (int i = 1; i < n; i +=2) {
            cnt ++;
            cout << cnt << ' ' << cnt << ' ';
        }
        cout << '\n';
    } else {
        if (n < 27) {
            cout << -1 << endl;
        } else {
            a[1] = a[10] = a[26] = 1;
            a[23] = a[27] = 2;
            int cnt = 3;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == 0) a[i] = a[i + 1] = ++cnt;
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
}

int main() {

    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}