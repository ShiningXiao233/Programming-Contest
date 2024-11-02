/*
a_i / b_i 与 a_j / b_j 的关系
三种方案：
1. 记录 mp[x][y] 表示 x的所有因子中，关于y的倍数有多少个。 即 b是x的因子，a是y的倍数。
    那么对于每一个a_i,b_i只需要加上 mp[a_i][b_i] 即可。（维护的代价太大）
2. 记录 mp[x][y]，表示 x的所有因子中，y多少个，即b是x的因子，a是y。
    那么对于每一个a_i,b_i只需要加上 mp[a_i][k * b_i] 即可。（维护和计数的代价太大）
3. 记录 mp[x][y]，表示 x中，y的倍数有多少个，即 b是x，a是y的倍数。
    那么对于每一个a_i,b_i只需要加上 mp[a_i / k][b_i] 即可。（代价均摊）
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int N = 500004;

unordered_map<int, int> mp[N];
#include <vector>

vector<int> d[N];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        mp[i].clear();
    }
    int a, b, g;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a; b = i;
        g = gcd(a, b);
        a /= g; b /= g;
        for (int v : d[a]) {
            if (mp[v].find(b) != mp[v].end()) {
                ans += mp[v][b];
            }
        }
        for (int v : d[a]) {
            mp[b][v] ++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    for (int i = 1; i < N; ++i) for (int j = i; j < N; j += i) d[j].push_back(i);
    int t;
    cin >> t;
    while (t --) {
        sol();
    }
    return 0;
}