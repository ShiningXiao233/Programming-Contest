#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 5e5+100;
int n;

vector<int> G[N];
int c[N], cnt;

void dfs(int u, int fa, int dep) {
	int Gn = 0;
	for (int v : G[u]) {
		if (v == fa) continue;
		dfs(v, u, dep + 1);
		Gn ++;
	}
	if (!Gn) {
		c[++cnt] = dep;
	} 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = 0;
	for (int u : G[1]) {
		cnt = 0;
		dfs(u, 1, 1);
		sort(c + 1, c + cnt + 1);
		for (int i = 2; i <= cnt; ++i) {
			c[i] = max(c[i], c[i - 1] + 1);
		}
		ans = max(ans, c[cnt]);
	}
	cout << ans << '\n';
	return 0;
}
