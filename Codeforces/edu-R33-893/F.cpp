#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
int n, m, r;
const int N = 1e5+100;
int a[N], dep[N], dfn[N], DFN = 0, Sz[N];
vector<int> G[N], vv;

void dfs(int u, int f = 0) {
	vv.push_back(u);
	dep[u] = dep[f] + 1;
	dfn[u] = ++ DFN;
	Sz[u] = 1;
	for (int v : G[u]) {
		if (v == f) continue;
		dfs(v, u);
		Sz[u] += Sz[v];
	}
}

struct node {
	int l, r;
	int val;
}s[N * 32 * 4];

int idx = 0;
int root[N];

void upd(int& now, int pre, int l, int r, int pos, int v) {
	now = ++idx;
	s[now] = s[pre];
	if (l == r) {
		s[now].val = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) {
		upd(s[now].l, s[pre].l, l, mid, pos, v);
	} else {
		upd(s[now].r, s[pre].r, mid + 1, r, pos, v);
	}
	s[now].val = min(s[s[now].l].val, s[s[now].r].val);
}

int query(int L, int R, int id, int l, int r) {
	if (L > r || R < l) return static_cast<int>(2e9);
	if (L <= l && r <= R) {
		return s[id].val;
	}
	int mid = (l + r) >> 1;
	int ansl = query(L, R, s[id].l, l, mid);
	int ansr = query(L, R, s[id].r, mid + 1, r);
	return min(ansl, ansr);
}

int main()
{
#ifdef INPUT
	freopen("1.txt", "r", stdin);
#endif
	cin >> n >> r;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(r);
	sort(vv.begin(), vv.end(), [](int a, int b) {
		return dep[a] < dep[b];
	});
	s[0].val = 2e9;
	int pre = 0;
	for (int v : vv) {
		upd(root[dep[v]], root[dep[pre]], 1, n, dfn[v], a[v]);
		pre = v;
	}
	cin >> m;
	int lans = 0;
	int x, k;
	
	while (m --) {
		cin >> x >> k;
		x = (x + lans) % n + 1;
		k = (k + lans) % n;
		k = dep[x] + k;
		k = min(k, dep[vv.back()]);
		lans = query(dfn[x], dfn[x] + Sz[x] - 1, root[k], 1, n);
		cout << lans << '\n';
	}
	return 0;
}
