#include <iostream>

using namespace std;
int H, W;
int n;
int a[10], b[10];
bool flag = 0;
int vis[14][14], vvs[14];

bool chk() {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; ++j) {
            if (vis[i][j] > 1) return 0;
        }
    }
    return 1;
}

bool chkok() {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; ++j) {
            if (vis[i][j] != 1) return 0;
        }
    }
    return 1;
}

void dfs(int bbx) {

    if (chkok()) {
        flag = 1;
        return;
    }
    
    if (bbx > n) return;

    int ix = -1, iy = -1;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (vis[i][j] == 0) {
                ix = i;
                iy = j;
                break;
            }
        }
        if (ix != -1) break;
    }

    for (int xx = 1; xx <= n; ++xx) {
        if (vvs[xx]) continue;
        vvs[xx] = 1;
        int idx = xx;
        if (ix + a[idx] - 1 <= H && iy + b[idx] - 1 <= W) {
            for (int i = 0; i < a[idx]; ++i) {
                for (int j = 0; j < b[idx]; ++j) {
                    vis[i + ix][j + iy] ++;
                }
            }
            if (chk()) {
                dfs(bbx + 1);
                if (flag) return;
            }
            for (int i = 0; i < a[idx]; ++i) {
                for (int j = 0; j < b[idx]; ++j) {
                    vis[i + ix][j + iy] --;
                }
            }
        }

        swap(a[idx], b[idx]);

        if (ix + a[idx] - 1 <= H && iy + b[idx] - 1 <= W) {
            for (int i = 0; i < a[idx]; ++i) {
                for (int j = 0; j < b[idx]; ++j) {
                    vis[i + ix][j + iy] ++;
                }
            }
            if (chk()) {
                dfs(bbx + 1);
                if (flag) return;
            }
            for (int i = 0; i < a[idx]; ++i) {
                for (int j = 0; j < b[idx]; ++j) {
                    vis[i + ix][j + iy] --;
                }
            }
        }
        vvs[xx] = 0;

    }
    
}

int main() {
    cin >> n >> H >> W;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    dfs(1);
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}