# include <bits/stdc++.h>
# define TIME 1e3 * clock() / CLOCKS_PER_SEC
using std :: cin; using std :: cout; using std :: max;
using std :: min; using std :: cerr; using std :: vector; 
typedef long long i64; 
typedef std :: pair < int, int > pii; 
const int N = 1e5 + 50, Mod = 1e9 + 7;
i64 dp[251][1 << 15][2][2]; 
int n, m; 
char ch[251][251];
// (x, y) 表示当前的坐标， st 表示哪些列已经被上面的摄像头覆盖。 
// hav 表示是否已经有一个没有被覆盖的空格，cover 表示当前行的左端是否存在一个摄像头能覆盖到当前位置。 
i64 dfs(int x, int y, int st, bool hav, bool cover)
{
	if(y == m) return dfs(x + 1, 0, st, hav, false); // 到达一行的末尾，失去行的限制。  
	if(x == n) return 1; 
	i64 &res = dp[x * m + y][st][hav][cover]; 
	if(res != -1) return res; 
	res = 0; 
	if(ch[x][y] == '.') {
		if(cover || ((st >> y) & 1)) res = dfs(x, y + 1, st, hav, cover); // 当前位置已经被覆盖了， 可以直接前往下一个位置 
		res += dfs(x, y + 1, st | (1 << y), hav, true); // 尝试在当前位置放置一个摄像头，这两种是不同的方案 
		res %= Mod; 
		if(hav == false && cover == false && !((st >> y) & 1)) { // 如果当前位置尚没有被覆盖且还有空一格的机会 
			res += dfs(x, y + 1, st, true, cover); // 尝试跳过当前的空格 
			res %= Mod; 
		}
	} else {
		res = dfs(x, y + 1, st & (~(1 << y)), hav, false); // 遇到了一个障碍， 那么当前行的左端和当前列的上端的摄像头被阻断。 
	}
	return res; 
} 
int main()
{
	std :: ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	cin >>n >>m; 
	for(int i = 0; i < n; i ++) cin >>ch[i]; 
	if(n < m) {
		for(int i = 0; i < n; i ++) {
			for(int j = i; j < m; j ++) std :: swap(ch[i][j], ch[j][i]); 
		}
		std :: swap(n, m); 
	}
	memset(dp, -1, sizeof(dp)); 
	cout <<dfs(0, 0, 0, false, false) <<"\n"; 
	return 0; 
}