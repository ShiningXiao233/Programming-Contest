
def dijkstra(s, G, dis, Hs):
    import heapq
    q = []
    dis[s][0] = 0
    if Hs[s]: 
        dis[s][1] = 0
        heapq.heappush(q, (dis[s][1], s, 1))
    heapq.heappush(q, (dis[s][0], s, 0))
    while q:
        c, u, z = heapq.heappop(q)
        if dis[u][z] != c: continue
        for v, w in G[u]:
            if z == 0:
                vz = 1 if Hs[v] else 0
                if dis[v][vz] > c + w:
                    dis[v][vz] = c + w
                    heapq.heappush(q, (dis[v][vz], v, vz))
                pass
            if z == 1:
                if dis[v][1] > c + w // 2:
                    dis[v][1] = c + w // 2
                    heapq.heappush(q, (dis[v][1], v, 1))
    pass

def sol():
    
    n, m, h = map(int, input().split())
    Hs = [False for _ in range(n)]
    h = list(map(int, input().split()))
    G = [[] for _ in range(n)]
    inf = int(10**15)
    dis1 = [[inf for _ in range(2)] for _ in range(n)]
    dis2 = [[inf for _ in range(2)] for _ in range(n)]
    for i in h:
        Hs[i - 1] = True
    while m > 0:
        a, b, c = map(int, input().split())
        m -= 1
        a -= 1
        b -= 1
        G[a].append((b, c))
        G[b].append((a, c))
    dijkstra(0, G, dis1, Hs)
    dijkstra(n - 1, G, dis2, Hs)
    ans = inf
    for i in range(n):
        ans = min(ans, max(min(dis1[i]), min(dis2[i])))
    print(-1 if ans == inf else ans)
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1