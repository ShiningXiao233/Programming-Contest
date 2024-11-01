
MOD1 = 998244353
MOD2 = 1000000007

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
        for v, c in G[u]:
            if dis[u] + c < dis[v]:
                dis[v] = dis[u] + c
                heapq.heappush(q, (dis[v], v))
                cnt1[v] = cnt1[u]
                cnt2[v] = cnt2[u]

            elif dis[u] + c == dis[v]:
                cnt1[v] += cnt1[u]
                cnt2[v] += cnt2[u]
                cnt1[v] %= MOD1
                cnt2[v] %= MOD2
                pass
    pass

def sol():
    n, m = map(int, input().split())
    G = [[] for _ in range(n + 1)]
    cnta1 = [[] for _ in range(n + 1)]
    cnta2 = [[] for _ in range(n + 1)]
    cntb1 = [[] for _ in range(n + 1)]
    cntb2 = [[] for _ in range(n + 1)]
    dis1 = [20000000002000000000 for _ in range(n + 1)]
    dis2 = [20000000002000000000 for _ in range(n + 1)]
    edge = []
    for i in range(m):
        a, b, c = map(int, input().split())
        G[a].append((b, c))
        G[b].append((a, c))
        edge.append((a, b, c))
    dijkstra(1, G, dis1, cnta1, cnta2)
    dijkstra(n, G, dis2, cntb1, cntb2)
    ans = []
    # print(cnta1[n], cntb1[n])
    for a, b, c in edge:
        if dis1[a] + dis2[b] + c == dis1[n]:
            if cnta1[n] == cnta1[a] * cntb1[b] % MOD1 and cnta2[n] == cnta2[a] * cntb2[b]:
                ans.append('Yes')
                continue
            pass
        elif dis1[b] + dis2[a] + c == dis1[n]:
            a, b = b, a
            if cnta1[n] == cnta1[a] * cntb1[b] % MOD1 and cnta2[n] == cnta2[a] * cntb2[b]:
                ans.append('Yes')
                continue
            pass
            pass

        ans.append('No')
    print('\n'.join(ans))
    pass

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1