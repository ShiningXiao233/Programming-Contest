def sol():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    l, r = 0, 0
    if n % 2 == 1:
        l, r = n // 2, n // 2
    else:
        l, r = n // 2 - 1, n // 2
        if a[l] == a[r]: ans += 1
    while l > 0:
        l -= 1
        r += 1
        tmp = [a[l], a[l + 1], a[r - 1], a[r]]
        tmp.sort()
        if tmp[0] == tmp[3]: ans += 2
        elif tmp[0] == tmp[2]: ans += 1
        elif tmp[1] == tmp[3]: ans += 1
        else: ans += 0
    print(ans)
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1