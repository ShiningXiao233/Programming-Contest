def sol():
    n, m = map(int, input().split())
    a = []
    while m > 0:
        x, y = map(int, input().split())
        a.append((x, y))
        m -= 1
    a.sort()
    b = [a[0][1]]
    for i in range(1, len(a)):
        if a[i][0] == a[i - 1][0]:
            b[-1] += a[i][1]
        else: b.append(a[i][1])
    b.sort(reverse=True)
    print(sum(b[0:n]))

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1