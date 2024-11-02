def sol():
    n, m = map(int, input().split())
    a = dict()
    while m > 0:
        x, y = map(int, input().split())
        if x not in a:
            a[x] = y
        else: a[x] += y
        m -= 1
    a = list(a.values())
    a.sort(reverse=True)
    print(sum(a[0:n]))

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1