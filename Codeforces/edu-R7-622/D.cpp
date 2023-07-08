#include <iostream>

using namespace std;
const int N = 1e6+100;
int a[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int pl1 = 1, pr1 = n, pl2 = n + 1, pr2 = n + n - 1;
	
	for (int i = 1; i < n; ++i) {
		if (i & 1) {
			a[pl1 ++] = i;
			a[pr1 --] = i;
		} else {
			a[pl2 ++] = i;
			a[pr2 --] = i;
		}
	}
	if (pl1 <= pr1) {
		a[pl1] = n;
		a[n + n] = n;
	} else {
		a[pl2] = n;
		a[n + n] = n;
	}
	for (int i = 1; i <= 2 * n; ++i) {
		cout << a[i] << ' ';
	}
	return 0;
}
