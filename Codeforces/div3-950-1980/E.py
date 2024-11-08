def sol():
    n, m = map(int, input().split())
    pos = [(0, 0) for i in range(0, n * m + 1)]
    col = [-1 for i in range(m)]
    row = [-1 for i in range(n)]
    for i in range(n):
        a = list(map(int, input().split()))
        for j in range(m):
            pos[a[j]] = (i, j)
    flag = True
    for i in range(n):
        a = list(map(int, input().split()))
        for j in range(m):
            x, y = pos[a[j]]
            if row[x] == -1 or row[x] == i:
                row[x] = i
            else: flag = False
            if col[y] == -1 or col[y] == j:
                col[y] = j
            else: flag = False
    print('yes' if flag else 'no')
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1