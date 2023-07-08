#include <bits/stdc++.h>

using namespace std;
const int N = 503;
int n, m;
int f[N][N];
int fv[N];

void updata(int u = 1) {
    int k, v;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> v;
        f[u][v] = 1;
        f[v][u] = 1;
    }
}
char ook[5];
void dfs(int u = 1, int fa = 0) {
    fv[u] = 1;
    updata(u);
    for (int v = 1; v <= n; ++v) {
        if (f[u][v] && !fv[v]) {
            cout << v << endl;
            if (v == n) {
                cin >> ook;
                exit(0);
            }
            dfs(v, u);
            updata(u);
        }
    }
    cout << fa << endl;
}

int main() {
    cin >> n >> m;
    dfs(1);
    updata();
    return 0;
}