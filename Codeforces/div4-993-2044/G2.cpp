#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 100;
const int MOD = 998244353;
using ll = long long;

vector<int> G[N];
int low[N], dfn[N], DFN;
int belong[N], cnt, cntb[N]; 
int n;
#include <stack>
stack<int> st;
bool ins[N];
int ans[N], r[N];
queue<int> q;

void tarjan(int u) {
    dfn[u] = low[u] = ++DFN;
    ins[u] = true;
    st.push(u);
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        } else if (ins[v]) {
            low[u] = min(dfn[v], low[u]);
        }
    }
    if (dfn[u] == low[u]) {
        cnt ++;
        cntb[cnt] = 0;
        int v;
        do {
            v = st.top(); st.pop();
            belong[v] = cnt;
            ins[v] = false;
            q.push(v);
            cntb[cnt] ++;

        } while(v != u);
    }
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        dfn[i] = 0;
        ans[i] = 1;
    }    
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
        G[r[i]].push_back(i);
    }
    DFN = cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (belong[u] != belong[r[u]]) {
            if (cntb[belong[r[u]]] == 1)
                ans[belong[r[u]]] += ans[belong[u]];
            else {
                ans[belong[r[u]]] = max(ans[belong[r[u]]], ans[belong[u]] + 1);
            }
            
        }
    }

    int AA = 0;
    for (int i = 1; i <= n; ++i) {
        AA = max(AA, ans[i] + 1);
    }
    cout << AA << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
}