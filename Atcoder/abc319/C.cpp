#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;
const double Fg = 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;
int a[10];

int dep[20], vis[20];
int ans = 0;
int tt = 0;
int row[7], col[7], r[4];
int flag = 0;

bool get(int &x, int v, int gg = 0) {
    // if (gg && flag) {
    //     cout << x << ' ' << v << endl;
    // }
    if (x == 0) x = v;
    else if (x > 0) {
        if (x == v) x = -v;
        else x = 0;
    }
    else if (x < 0 && (x != (-v))) {
        // cout << "hhh\n";
        return 0;
    }

    return 1;
}



bool chk() {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= 9; ++i) {
        // if (flag) {
        //     cout << " == " << i << ' ' << dep[i] << ' ' << a[dep[i]] << endl;
        // }
        if (!get(row[dep[i] / 3], a[dep[i]])) return 0;
        
        if (!get(col[dep[i] % 3], a[dep[i]], 1)) return 0;
        // if (flag)
        // cout << "---" << endl;
        if (dep[i] == 0) {
            if (!get(r[0], a[dep[i]])) return 0;
        } else if (dep[i] == 1) {

        } else if (dep[i] == 2) {
            if (!get(r[1], a[dep[i]])) return 0;
        } else if (dep[i] == 3) {

        } else if (dep[i] == 4) {
            if (!get(r[0], a[dep[i]])) return 0;
            if (!get(r[1], a[dep[i]])) return 0;
        } else if (dep[i] == 5) {

        } else if (dep[i] == 6) {
            if (!get(r[1], a[dep[i]])) return 0;
        } else if (dep[i] == 7) {

        } else if (dep[i] == 8) {
            if (!get(r[0], a[dep[i]])) return 0;
        }
    }
    return 1;
}

void dfs(int x) {
    
    if (x > 9) {
        // if (dep[1] == 6 && dep[2] == 3 && dep[3] == 0) {
        //     flag = 1;
        //     // cout <<chk() << '-' << endl;
        //     exit(1);
        // }
        if (chk() == 1) ++ans;
        return;
    }
    for (int i = 0; i < 9; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            dep[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

void sol() {
    for (int i = 0; i < 9; ++i) {
        cin >> a[i];
    }
    ans = 0;
    dfs(1);
    // dep[1] = 6;
    // dep[2] = 3;
    // dep[3] = 0;
    // dep[4] = 6;
    // dep[5] = 6;
    // dep[6] = 6;
    // dep[7] = 6;
    // dep[8] = 6;
    // dep[9] = 6;
    // cout << chk() << endl;
    // cout << ans << endl;
    double tans = 1.0 * ans / Fg;
    // cout << ans << ' ' << tt << endl;
    printf("%.15f\n", tans);
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