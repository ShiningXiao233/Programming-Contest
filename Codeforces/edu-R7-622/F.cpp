#include <iostream>

using namespace std;
const int MOD = 1e9 + 7, N = 1e6+100;

int qp(int x, int p = MOD - 2) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1ll * res * x % MOD;
		p >>= 1;
		x = 1ll * x * x % MOD;
	}
	return res;
}
int g[N];
int fc[N], rfc[N];
#define dec(x) (x >= MOD ? x - MOD : x)

int lglr(int n, int k) {
	const int K = k + 2;
	fc[0] = 1;
	for (int i = 1; i <= K; ++i) {
		g[i] = g[i - 1] + qp(i, k);
		g[i] = dec(g[i]);
		fc[i] = 1ll * fc[i - 1] * i % MOD;
	}
	rfc[K] = qp(fc[K]);
	for (int i = K; i > 0; --i) {
		rfc[i - 1] = 1ll * rfc[i] * i % MOD;
	}
	if (n <= K) {
		return g[n];
	}
	int Fx = 1;
	for (int i = 1; i <= K; ++i) {
		Fx = 1ll * Fx * (n - i) % MOD;
	}
	int res = 0;
	for (int i = 1; i <= K; ++i) {
		int tmp = 0;
		tmp = 1ll * g[i] * Fx % MOD * qp(n - i) % MOD;
		
		tmp = 1ll * rfc[i - 1] * tmp % MOD * rfc[K - i] % MOD;
		if ((K - i) % 2 == 1) {
			tmp = MOD - tmp;
		}
		res += tmp;
		res = dec(res);
	}
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << lglr(n, k) << '\n';
	return 0;
}
