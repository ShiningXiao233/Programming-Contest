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
int colt[N], rowt[N];

int ans;

bool getpp() {

    for (int i = 1; i <= n; ++i)  colt[i] = -1;
    for (int i = 1; i <= m; ++i)  rowt[i] = -1;
    

    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
        if (cntcc[i] > 1) {
            for (int j = 0; j < 26; ++j) {
                if (cntc[i][j] == cntcc[i]) {
                    colt[i] = j;
                    flag = 1;
                    break;
                }
            }  
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (cntrr[i] > 1) {
            for (int j = 0; j < 26; ++j) {
                if (cntrr[i] == cntr[i][j]) {
                    rowt[i] = j;
                    flag = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int j;
        if (colt[i] > -1) {
            j = colt[i];
            ans -= cntcc[i];
            cntcc[i] = 0;
            cntc[i][j] = 0;

            for (int k = 1; k <= m; ++k) {
                if (cntr[k][j] > 0) {
                    cntr[k][j] --;
                    cntrr[k] --;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        int j;
        if (rowt[i] > -1) {
            j = rowt[i];
            ans -= cntrr[i];
            cntrr[i] = 0;
            cntr[i][j] = 0;

            for (int k = 1; k <= n; ++k) {
                if (cntc[k][j] > 0) {
                    cntc[k][j] --;
                    cntcc[k] --;
                }
            }
        }
    }

    return flag;
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
    ans = n * m;
    while(getpp());
    cout << ans << '\n';
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