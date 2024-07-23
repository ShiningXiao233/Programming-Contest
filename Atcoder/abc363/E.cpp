#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;



int h[1003][1003];
int dis[1003][1003];
#include <tuple>

using tp = tuple<int, int, int>;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void sol() {
    int H, W, Y;
    cin >> H >> W >> Y;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> h[i][j];
            dis[i][j] = 1e9;
        }
    }
    priority_queue<tp, vector<tp>, greater<tp>> q;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (i == 1 || i == H || j == 1 || j == W) {
                dis[i][j] = h[i][j];
                q.push({dis[i][j], i, j});
            }
        }
    }

    // cout << " -- " << endl;
    while (!q.empty()) {
        auto tmp = q.top(); q.pop();
        int w = get<0>(tmp);
        int x = get<1>(tmp);
        int y = get<2>(tmp);
        if (w > dis[x][y]) continue;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int tw = max(h[xx][yy], w);
            if (tw < dis[xx][yy]) {
                dis[xx][yy] = tw;
                q.push({tw, xx, yy});
            }
        }
    }
    vector<int> ff(1e5+100);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            ff[dis[i][j]] ++;
        }
    }
    for (int i = 1; i <= Y; ++i) {
        ff[i] += ff[i - 1];
        cout << H * W - ff[i] << '\n';
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