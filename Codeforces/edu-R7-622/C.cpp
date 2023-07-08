#include <iostream>

using namespace std;
const int N = 2e5+100;
int a[N], p[N];
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != a[i - 1]) p[i] = i - 1;
		else p[i] = p[i - 1];
	}
	int l, r, x;
	while (m--) {
		cin >> l >> r >> x;
		if (a[r] != x) {
			cout << r << '\n';
		}
		else {
			if (p[r] < l) cout << -1 << '\n';
			else cout << p[r] << '\n';
		}
	}
	return 0;
}
