#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    string s;
    cin >> s;
    for(auto it : s) {
        if(it == 'a' || it == 'e' || it == 'o' || it == 'i' || it == 'u') {
            continue;
        }
        cout << it;
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
    exit(0);
}