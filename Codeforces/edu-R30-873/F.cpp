#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int lim = 2e5+100;

struct sam
{
	int ch[26];
	int link, len;
	void clear()
	{
		memset(ch, 0, sizeof(ch));
		link = len = 0;
	}
}node[lim * 2];
int last = 1, tot = 1, num[lim * 2];
char s[lim], t[lim];

void extend(int c, int np)
{
	int u = last, v = last = ++tot;
	node[v].len = node[u].len + 1;
	num[v] = np;
	for (; u && !node[u].ch[c]; u = node[u].link) node[u].ch[c] = v;
	if (!u) node[v].link = 1;
	else
	{
		int _v = node[u].ch[c];
		if (node[_v].len == node[u].len + 1) node[v].link = _v;
		else
		{
			int new_v = ++tot;
			node[new_v] = node[_v];
			node[new_v].len = node[u].len + 1;
			node[_v].link = node[v].link = new_v;
			for (; u && node[u].ch[c] == _v; u = node[u].link) node[u].ch[c] = new_v;
		}
	}
}

vector<int> G[lim * 2];
ll ans = 0;

void dfs(int u)
{
	for (int v : G[u])
	{
		dfs(v);
		num[u] += num[v]; 
	}
	ans = max(ans, 1ll * num[u] * node[u].len);
}

void sol()
{
	last = tot = 1;
	int n;
	cin >> n >> s >> t;
	for (int i = 0; s[i]; ++i) extend(s[i] - 'a', t[i] == '0');
	for (int i = 2; i <= tot; ++i)
		G[node[i].link].push_back(i);
	dfs(1);	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--) sol();
	return 0;
}