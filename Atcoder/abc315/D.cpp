#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2e3+100;
const int MOD = 998244353;

char s[N][N];
int n, m;
int cntc[N][26], cntr[N][26];
int cntcc[N], cntrr[N];


void getpp() {

}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cntc[i][s[i][j] - 'a'] ++;
        }
        cntcc[i] = m;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cntr[i][s[j][i] - 'a'] ++;
        }
        cntrr[i] = n;
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