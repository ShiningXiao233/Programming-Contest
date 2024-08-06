#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

void sol() {
    int n, k;
    cin >> n >> k;
    int g = 1;
    vector<int> a(n, -1);
    stack<int> stk;
    stk.push(n + 1);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        stk.push(a[i]);
        while (!stk.empty() && stk.top() == g) {
            stk.pop();
            g ++;
        }
    }
    for (int i = k; i < n; ++i) {
        a[i] = stk.top() - 1;
        stk.push(a[i]);
        while (!stk.empty() && stk.top() == g) {
            stk.pop();
            g ++;
        }
    }
    
    if (stk.empty()) {
        for (int v : a) {
            cout << v << ' ';
        }
    } else {
        cout << -1 << '\n';
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