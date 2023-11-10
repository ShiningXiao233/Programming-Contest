#include <iostream>

using namespace std;

#include <vector>

const int N = 1e5+100;

vector<int> RG[N];
int ans[N], rd[N];
int n, m;

#include <queue>

typedef priority_queue<int> Pg;

int main() {
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;

        RG[v].push_back(u);
        rd[u] ++;

       
    }
    Pg q;
    for (int i = 1; i <= n; ++i) {
        if (rd[i] == 0) q.push(i);
    }
    int cnt = n;
    while (!q.empty()) {
        
        u = q.top(); q.pop();
        ans[u] = cnt --;
        for (int v : RG[u]) {
            rd[v] --;
            if (rd[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    } 
    return 0;
}