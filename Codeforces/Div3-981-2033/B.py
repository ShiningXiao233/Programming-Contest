def sol():
    n = int(input())
    a = [[] for _ in range(n)]
    for _ in range(n):
        a[_] = list(map(int, input().split()))
    ans = 0
    for _ in range(n):
        i, j = 0, _
        p = 0
        while i < n and j < n:
            p = min(p, a[i][j])
            i += 1
            j += 1
        if p < 0: ans += p
    for _ in range(1, n):
        i, j = _, 0
        p = 0
        while i < n and j < n:
            p = min(p, a[i][j])
            i += 1
            j += 1
        if p < 0: ans += p
        
    print(-ans)
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1