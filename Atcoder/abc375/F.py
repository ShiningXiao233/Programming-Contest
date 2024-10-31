def sol():
    n, m, q = map(int, input().split())
    INF = 400000000000
    dis = [[INF for _ in range(n)] for _ in range(n)]
    for i in range(n): dis[i][i] = 0
    M = []
    Q = []
    for i in range(m):
        M.append(list(map(int, input().split())))
        M[i][0] -= 1
        M[i][1] -= 1
    for i in range(q):
        Q.append(list(map(int, input().split())))
        if Q[i][0] == 1:
            id = Q[i][1] - 1
            Q[i] = (1, M[id][0], M[id][1], M[id][2])
            M[id][0] = -1
    for a, b, c in M:
        if a != -1:
            dis[b][a] = dis[a][b] = min(dis[a][b], c)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
    Q.reverse()
    ans = []
    for q in Q:
        if q[0] == 1:
            _, x, y, c = q
            for i in range(n):
                for j in range(n):
                    dis[i][j] = min(dis[i][j], dis[i][x] + dis[y][j] + c,
                                    dis[i][y] + dis[x][j] + c)
        if q[0] == 2:
            _, x, y = q
            x -= 1
            y -= 1
            p = dis[x][y] if dis[x][y] < INF else -1
            ans.append(str(p))
    ans.reverse()
    print('\n'.join(ans))
    pass

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1