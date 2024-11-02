def sol():
    n, m = map(int, input().split())
    s = [None for _ in range(n)]
    for i in range(n):
        s[i] = input()
        s[i] = [i for i in s[i]]
    x, y = 0, 0
    tx, ty = n - 1, m - 1
    ans = 0
    while x <= tx and y <= ty:
        a : list[str] = s[x][y : ty + 1]
        for i in range(x + 1, tx + 1, 1):
            a.append(s[i][ty])
        for i in range(ty - 1, y - 1, -1):
            a.append(s[tx][i])
        for i in range(tx - 1, x, -1):
            a.append(s[i][y])
        a.append(a[0])
        a.append(a[1])
        a.append(a[2])
        for i in range(len(a)):
            if a[i:i + 4] == ['1', '5', '4', '3']:
                ans += 1
        x += 1; y += 1
        tx -= 1; ty -= 1
    print(ans)

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1