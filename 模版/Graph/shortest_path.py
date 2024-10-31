

def dijkstra(S, G, dis):
    """最短路
    S: 源点
    G: 边
    dis: 最小距离
    """
    import heapq
    q = []
    dis[S] = 0
    heapq.heappush(q, (0, S))
    while q:
        w, u = heapq.heappop(q)
        if w != dis[u]: continue
        for v, c in G[u]:
            if dis[u] + c < dis[v]:
                dis[v] = dis[u] + c
                heapq.heappush(q, (dis[v], v))
    pass

def sol():
    n, m, s = map(int, input().split())
    dis = [100000000000 for _ in range(n)]
    G = [[] for _ in range(n)]
    while m > 0:
        a, b, c = map(int, input().split())
        G[a - 1].append((b - 1, c))
        m -= 1
    s -= 1
    dijkstra(s, G, dis)
    for _ in range(n):
        dis[_] = str(dis[_])
    print(' '.join(dis))
    pass

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1