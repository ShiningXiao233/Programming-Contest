
def sol():
    m, x = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    res = 0
    import heapq
    q = []
    for c in a:
        if res >= c:
            res -= c
            ans += 1
            heapq.heappush(q, -c)
        else:
            if q:
                cc = -heapq.heappop(q)
                if cc > c:
                    res = res + cc - c
                    heapq.heappush(q, -c)
                else:
                    heapq.heappush(q, -cc)
            pass
        res += x

    print(ans)

if __name__ == '__main__':
    t = input()
    t = int(t)
    while t > 0:
        t -= 1
        sol()