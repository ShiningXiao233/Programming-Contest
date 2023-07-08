#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int A, B;
    cin >> A >> B;
    if ((A == 1 && B == 2) ||
        (A == 2 && B == 3) ||
        (A == 4 && B == 5) ||
        (A == 5 && B == 6) ||
        (A == 7 && B == 8) ||
        (A == 8 && B == 9)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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
}