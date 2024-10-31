
def dijkstra(S, G, dis, cnt1, cnt2):
    import heapq
    q = []
    dis[S] = 0
    cnt1[S] = 1
    cnt2[S] = 1
    heapq.heappush(q, (0, S))
    while q:
        w, u = heapq.heappop(q)
        if w != dis[u]: continue
        for v, c, _ in G[u]:
            if dis[u] + c < dis[v]:
                dis[v] = dis[u] + c
                heapq.heappop(q, (dis[v], v))
                cnt1[v] = cnt1[u]
                cnt2[v] = cnt2[u]

            elif dis[u] + c == dis[v]:
                cnt1[v] += cnt1[u]
                cnt2[v] += cnt2[u]
                
                pass
    pass

def sol():
    
    pass

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1