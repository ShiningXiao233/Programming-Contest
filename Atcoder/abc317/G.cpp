#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int N = 1e2+10;
const int MOD = 998244353;

struct edge {
    int v, next, flow, flag;
}s[N * N * 2];
int S = N + N, T = S + 1;
int op = 0, head[N * 2 + 10];
int n, m;

void add(int a, int b, int c) {
    s[op].flow = c, s[op].next = head[a], s[op].flag = 0, s[op].v = b, head[a] = op ++;
    s[op].flow = 0, s[op].next = head[b], s[op].flag = 0, s[op].v = a, head[b] = op ++;
}

int dep[N * 2 + 10], cur[N * 2 + 10];

bool findway() {
    memset(dep, -1, sizeof(dep));
    queue<int> q;
    dep[S] = 1;
    q.push(S); cur[S] = head[S];
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = s[i].next) {
            if (dep[s[i].v] == -1 && s[i].flow && !s[i].flag) {
                dep[s[i].v] = dep[u] + 1;
                cur[s[i].v] = head[s[i].v];
                if (s[i].v == T) return true;
                q.push(s[i].v);
            }
        }
    }
    return false;
}

int toflow(int u, int limit) {
    if (u == T) return limit;
    int res = 0, t, v;
    for (int i = cur[u]; ~i; i = s[i].next) {
        cur[u] = i;
        v = s[i].v;
        if (dep[v] == dep[u] + 1 && s[i].flow && !s[i].flag) {
            t = toflow(v, min(limit, s[i].flow));
            if (t == 0) dep[v] = -1;
            s[i].flow -= t; s[i ^ 1].flow += t;
            limit -= t; res += t;
        }
    }
    return res;
}

int dinic() {
    int res = 0;
    while (findway()) res += toflow(S, 1e9);
    return res;
}
int ans[N][N];

void sol() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    int x;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> x;
            add(i, N + x, 1);
        }
    }    
    for (int i = 1; i <= n; ++i) {
        add(N + i, T, 0);
        add(S, i, 0);
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = head[S]; ~i; i = s[i].next) {
            s[i].flow = 1;
            s[i ^ 1].flow = 0;
        }
        for (int i = head[T]; ~i; i = s[i].next) {
            s[i].flow = 0;
            s[i ^ 1].flow = 1;
        }
        
        int p = dinic();
        if (p != n) {
            cout << "No\n";
            exit(0);
        }
        for (int u = 1; u <= n; ++u) {
            for (int i = head[u]; ~i; i = s[i].next) {
                if (!s[i].flag && !s[i].flow) {
                    ans[j][u] = s[i].v - N;
                    s[i].flag = s[i ^ 1].flag = 1;
                    break;
                }
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << ans[j][i] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        sol();
    }
    exit(0);
}