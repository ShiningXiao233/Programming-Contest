#include <iostream>
#include <set>

using namespace std;
const int N = 1e5+100;
int n;
int a[N];
set<long long> cnt;

int main() {
    long long res = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        res += a[i];
    }
    if (res & 1ll) {
        cout << "NO\n";
        exit(0);
    } else {
        long long tmp = res / 2;
        res = 0;
        for (int i = 1; i <= n; ++i) {
            res += a[i];
            cnt.insert(a[i]);
            if (res == tmp) {
                cout << "YES\n";
                exit(0);
            }
            if (res > tmp) {
                if (res - tmp <= 1000000000ll) {
                    int aa = res - tmp;
                    if (cnt.count(aa)) {
                        cout << "YES\n";
                        exit(0);
                    }
                }
            }
        }
        cnt.clear();
        res = 0;
        for (int i = n; i >= 1; --i) {
            res += a[i];
            cnt.insert(a[i]);
            if (res == tmp) {
                cout << "YES\n";
                exit(0);
            }
            if (res > tmp) {
                if (res - tmp <= 1000000000ll) {
                    int aa = res - tmp;
                    if (cnt.count(aa)) {
                        cout << "YES\n";
                        exit(0);
                    }
                }
            }
        }
        cout << "NO\n";
    }
    return 0;
}