#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

struct netflow_pre
{
	static const int N = 200, M = 1e4, inf = 0x3f3f3f3f;
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
		memset(dis, -0x3f, sizeof(dis));
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
				if (flow[i] && dis[u] + w[i] > dis[v])
				{
					pre[v] = i;
					dis[v] = dis[u] + w[i];
					F[v] = min(F[u], flow[i]);
					if (vis[v]) continue;
					vis[v] = 1;
					if (!q.empty() && dis[v] >= dis[q.front()]) q.push_front(v);
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
            // cout << "--       " << F[T] << ' ' << dis[T] << '\n';
			int now = T;
			while (now != S)
			{
				flow[pre[now]] -= F[T];
				flow[pre[now] ^ 1] += F[T];
				now = son[pre[now] ^ 1];
			}

		}
	}
} res;

void sol() {
    int n;
    string s;
    vector<int> w(n), cnt(128, 0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (char c : s) cnt[c] ++;

    for (int i = 'a'; i <= 'z'; ++i) {
        res.add(res.S, i, cnt[i], 0);
    }
    for (int i = 1; i <= n / 2; ++i) {
        // cout << w[i - 1] << ' ' << w[n - i] << endl;
        res.add(i, res.T, 2, 0);
        for (int c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] == 0) continue;
            if (s[i - 1] == c && s[n - i] == c) {
                res.add(c, i, 1, max(w[n - i], w[i - 1]));

            }else if (s[i - 1] == c) {
                res.add(c, i, 1, w[i - 1]);
            } else if (s[n - i] == c) {
                res.add(c, i, 1, w[n - i]);
                // cout << " --- " << c << ' ' << i << ' ' << w[n - i] << endl;
            } else {
                res.add(c, i, 1, 0);
            }
        }
    }
    res.EK();
    cout << res.MinF << '\n';
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