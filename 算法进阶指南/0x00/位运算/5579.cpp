#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;
using ll = long long;

int pow(int a, int b, int p) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) res = res * a % p;
    }
    return res;
}

void sol() {
    int n;
    int res = 0;
    int a, b, p;
    cin >> p;
    cin >> n;
    while (n --) {
        cin >> a >> b;
        a %= p;
        res += pow(a, b, p);
        res %= p;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}