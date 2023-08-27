#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
const int N = 2e3 + 100;
const int MOD = 998244353;
char s[N][N];
int dis[N][N];

int n, m;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const char* tts = "^v<>#\0";

bool is_bond(char x) {
    for (int i = 0; tts[i]; ++i) {
        if (x == tts[i]) return 1;
    }
    return 0;
}
int Sx, Sy, Gx, Gy;
void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dis[i][j] = -1;
            if (s[i][j] == 'S') {
                Sx = i;
                Sy = j;
                dis[i][j] = 0;
            }
            if (s[i][j] == 'G') {
                Gx = i;
                Gy = j;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int fg = 0;
        for (int j = 1; j <= m; ++j) {
            if (is_bond(s[i][j])) fg = 0;
            if (s[i][j] == '>'){fg = 1;}
            if (is_bond(s[i][j])) {
                dis[i][j] = -1e9;
            }
            if (fg) dis[i][j] = -1e9;
        }
        fg = 0;
        for (int j = m; j >= 1; --j) {
            if (is_bond(s[i][j])) fg = 0;
            if (s[i][j] == '<') fg = 1;
            if (is_bond(s[i][j])) {
                dis[i][j] = -1e9;
            }
            if (fg) dis[i][j] = -1e9;
        }
    }

    for (int j = 1; j <= m; ++j) {
        int fg = 0;
        for (int i = 1; i <= n; ++i) {
            if (is_bond(s[i][j])) fg = 0;
            if (s[i][j] == 'v') fg = 1;
            if (is_bond(s[i][j])) {
                dis[i][j] = -1e9;
            }
            if (fg) dis[i][j] = -1e9;
        }
        fg = 0;
        for (int i = n; i >= 1; --i) {
            if (is_bond(s[i][j])) fg = 0;
            if (s[i][j] == '^') fg = 1;
            if (is_bond(s[i][j])) {
                dis[i][j] = -1e9;
            }
            if (fg) dis[i][j] = -1e9;
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         if (dis[i][j] >= -1) {
    //             cout << '.';
    //         } else {
    //             cout << "*";
    //         }
    //     }
    //     cout << "\n";
    // }

    queue<pair<int, int> > q;
    q.push({Sx, Sy});
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        int xx, yy;
        for (int i = 0; i < 4; ++i) {
            xx = u.first + dx[i];
            yy = u.second + dy[i];
            if (dis[xx][yy] == -1) {
                dis[xx][yy] = dis[u.first][u.second] + 1;
                q.push({xx, yy});
            }
        }
    }
    if (dis[Gx][Gy] > 0) {
        cout << dis[Gx][Gy] << '\n';
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