#include <iostream>

using namespace std;
/**
 * 普通版本
 * 字符的下标从1开始
 * sa[i] 代表第i小的后缀的起始位置
 * rk[i] 代表后缀i的排名
 * height[i] 代表排名第i的后缀与排名第i-1后缀的最长公共前缀
 */
namespace sa_0 {
const int lim = 1e5+5;
int sa[lim], height[lim], rk[lim];
/**
 * s是字符
 * n代表长度
 */
void get_SA(char *s, int n, int m = 128)
{
    int *c = new int[lim];
    int *y = new int[lim];
    int *x = new int[lim];
	for (int i = 1; i <= n; ++i) c[x[i] = s[i]] ++;
	for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
	for (int i = n; i >= 1; --i) sa[c[x[i]]--] = i;
	int num;
	for (int k = 1; k <= n; k <<= 1)
	{
		num = 0;
		memset(c, 0, sizeof(int) * (m + 3));
		for (int i = n - k + 1; i <= n; ++i) y[++num] = i;
		for (int i = 1; i <= n; ++i)
		{
			if (sa[i] > k) y[++num] = sa[i] - k;
			c[x[i]] ++;
		}
		for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
		for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i];
		for (int i = 1; i <= n; ++i) swap(x[i], y[i]);
		num = 1; x[sa[1]] = 1;
		for (int i = 2; i <= n; ++i)
			x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
		if (num == n) break;
		m = num;
	}
	for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
	int op = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (rk[i] == 1) continue;
		int j = sa[rk[i] - 1];
		if (op) --op;
		while (i + op <= n && j + op <= n && s[i + op] == s[j + op]) ++op;
		height[rk[i]] = op;
	}
    delete[] x;
    delete[] y;
    delete[] c;
}
}

/**
 * 结构体版本
 * 支持直接查询两个串的lcp（最长公共前缀）
 * 字符的下标从1开始
 */
namespace sa_1 {

const int lim = 1e5;
struct SA
{
	int sa[lim], lcp[lim], rk[lim], x[lim], y[lim], c[lim];
	int _lcp[15][lim];
	SA()
	{
		memset(_lcp, 0, sizeof(_lcp));
		memset(lcp, 0, sizeof(lcp));
		memset(sa, 0, sizeof(sa));
		memset(rk, 0, sizeof(rk));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
	}
	void get_SA(char *s, int n, int m = 128)
	{
		memset(c, 0, sizeof(int) * (m + 3));
		for (int i = 1; i <= n; ++i) c[x[i] = s[i]] ++;
		for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
		for (int i = n; i >= 1; --i) sa[c[x[i]]--] = i;
		int num = 0;
		for (int k = 1; k <= n; k <<= 1)
		{
			memset(c, 0, sizeof(int) * (m + 3));
			num = 0;
			for (int i = n - k + 1; i <= n; ++i) y[++num] = i;
			for (int i = 1; i <= n; ++i)
			{
				if (sa[i] > k) y[++num] = sa[i] - k;
				c[x[i]] ++;
			}
			for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
			for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i];
			for (int i = 1; i <= n; ++i) swap(x[i], y[i]);
			num = 1; x[sa[1]] = 1;
			for (int i = 2; i <= n; ++i)
				x[sa[i]] = (y[sa[i]] == y[sa[i -1]] && y[sa[i] + k] == y[sa[i -1] + k]) ? num : ++ num;
			if (num == n) break;
			m = num;
		}
		for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
		for (int i = 1, op = 0, j; i <= n; ++i, op = op ? --op : op)
		{
			if (rk[i] == 1) continue;
			j = sa[rk[i] - 1];
			while (i + op <= n && j + op <= n && s[i + op] == s[j + op]) ++op;
			_lcp[0][rk[i]] = lcp[rk[i]] = op;
		}
		for (int i = 1; i < 15; ++i)
			for (int j = 1; j + (1 << i) - 1 <= n; ++j)
				_lcp[i][j] = min(_lcp[i - 1][j], _lcp[i - 1][j + (1 << (i - 1))]);
	}
	int query(int xl, int xr)
	{
		int l = min(rk[xl], rk[xr]) + 1;
		int r = max(rk[xl], rk[xr]);
		if (l > r) return 0;
		int k = log2(r - l + 1);
		return min(_lcp[k][l], _lcp[k][r - (1 << k) + 1]);
	}
};

}



int main() {

    return 0;
}