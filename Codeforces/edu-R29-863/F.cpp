#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int N = 1e5 + 100;
const int MOD = 998244353;

struct netflow_pre
{
	static const int N = 1e4, M = 2e5, inf = 0x3f3f3f3f;
	int head[N], next[M], son[M], flow[M], w[M], dis[N], vis[N], pre[N], F[N];
	int S,T,idx = 0,Maxflow = 0,MinF = 0;
	netflow_pre(int s = 0,int t = N - 1)
	{
		S = s;
		T = t;
		memset(head, -1, sizeof(head));
	}
	void add(int a,int b,int c,int d)
	{  
		son[idx] = b, flow[idx] = c, w[idx] = d, next[idx] = head[a], head[a] = idx++;
		son[idx] = a, flow[idx] = 0, w[idx] = -d, next[idx] = head[b], head[b] = idx++;
	}
	bool spfa()
	{
		memset(dis, inf, sizeof(dis));
		memset(F, 0, sizeof(F));
		deque<int> q;
		int u,v;
		q.push_back(S);
		dis[S] = 0;
		F[S] = inf;
		while (!q.empty())
		{
			u = q.front(); q.pop_front();
			vis[u] = 0;
			for (int i = head[u]; ~i; i = next[i])
			{
				v = son[i];
				if (flow[i] && dis[u] + w[i] < dis[v])
				{
					pre[v] = i;
					dis[v] = dis[u] + w[i];
					F[v] = min(F[u], flow[i]);
					if (vis[v]) continue;
					vis[v] = 1;
					if (!q.empty() && dis[v] <= dis[q.front()]) q.push_front(v);
					else q.push_back(v);
				}
			}
		}
		return F[T] > 0;
	}
	void EK()
	{
		while (spfa())
		{
			Maxflow += F[T];
			MinF += F[T] * dis[T];
			int now = T;
			while (now != S)
			{
				flow[pre[now]] -= F[T];
				flow[pre[now] ^ 1] += F[T];
				now = son[pre[now] ^ 1];
			}

		}
	}
};

int n, q;
netflow_pre res;
int MN[100], MX[100];

void sol() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        MX[i] = n;
        MN[i] = 1;
        for (int j = 1; j <= n; ++j) {
            res.add(res.S, i, 1, 2 * j - 1);
        }
        res.add(n + i, res.T, 1, 0);
    }
    while (q --) {
        int opt, l, r, x;
        cin >> opt >> l >> r >> x;
        if (opt == 1) {
            for (int i = l; i <= r; ++i) {
                MN[i] = max(MN[i], x);
            }
        } else {
            for (int i = l; i <= r; ++i) {
                MX[i] = min(MX[i], x);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (MN[i] <= MX[i]) {
            for (int x = MN[i]; x <= MX[i]; ++x) {
                res.add(x, n + i, n, 0);
            }
        } else {
            cout << -1 << endl;
            return;
        }
    }
    res.EK();
    cout << res.MinF << '\n';
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