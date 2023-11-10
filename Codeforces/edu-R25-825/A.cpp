#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n;
    cin >> n;
    char *s = new char[n + 1];
    cin >> s;
    int f = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            cout << f;
            f = 0;
        } else {
            f++;
        }
    }
    cout << f << endl;

    delete[] s;

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