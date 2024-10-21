MOD = 998244353

def sol():
    global MOD
    n, m = map(int, input().split())
    dp = [[0 for _ in range(m + 1)] for _ in range(n)]
    way = [[0 for _ in range(m + 1)] for _ in range(m + 1)]
    way[0][0] = 1
    for i in range(0, m):
        for j in range(0, i + 1):
            way[i + 1][j + 1] += way[i][j] # [
            way[i + 1][j + 1] %= MOD
            if j > 0:
                way[i + 1][j - 1] += way[i][j] # ]
                way[i + 1][j - 1] %= MOD
    for i in range(0, m + 1, 2):
        dp[0][i] = way[m][i]
    for i in range(1, n):
        for j in range(0, m + 1, 2):
            for k in range(0, j + 1, 2):
                dp[i][j - k] += dp[i - 1][j] * way[m][k] % MOD
                dp[i][j - k] %= MOD
    print(dp[n - 1][0])
    pass

if __name__ == '__main__':
    t = 1
    while t > 0:
        sol()
        t -= 1