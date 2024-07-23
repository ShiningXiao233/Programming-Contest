#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5+100;
const int MOD = static_cast<int>(1e9 + 7);
char s[N * 3];
int n;

int main() {
    cin >> n;
    cin >> s;
    int res = 1, tmp = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            res = 1ll * res * (tmp / 2 + 1) % MOD;
            cout << tmp / 2 + 1 << endl;
            tmp = 0;
            
        } else {
            tmp ++;
        }
    }
    cout << tmp / 2 + 1 << endl;

    res = 1ll * res * (tmp / 2 + 1) % MOD;
    cout << res << endl;
    return 0;
}