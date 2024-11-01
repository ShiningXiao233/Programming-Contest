# dp[i][0] 不留当前点
# dp[i][1] 留当前点

import sys

def sol():
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    G = [[] for _ in range(n)]
    inf = int(10**12)
    dp = [[-inf for _ in range(2)] for _ in range(n)]
    f = [-1 for _ in range(n + 1)]
    for i in range(1, n):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)
    q = [0]
    for i in range(n):
        u = q[i]
        for v in G[u]:
            if v == f[u]: continue
            q.append(v)
            f[v] = u
    q.reverse()
    for u in q:
        # print(u, end=' ')
        dp[u][0] = 0
        dp[u][1] = max(0, a[u])
        for v in G[u]:
            if v == f[u]: continue
            dp[u][0] += max(dp[v])
            dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c)

    print(max(dp[0][0], dp[0][1], 0))
    pass

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        sol()
        t -= 1