def sol():
    n = input()
    a = list(map(int, input().split()))
    n = len(a)
    for i in range(n): a[i] -= 1
    # print(a)
    ans = 0
    for i in range(n):
        x = i
        cnt = 0
        while a[x] != -1:
            # print(x, a[x], " = ")
            cnt += 1
            tmp = x
            x = a[x]
            a[tmp] = -1
            # x, a[tmp] = a[x], -1
            
        ans += 0 if cnt <= 2 else (cnt + 1) // 2 - 1
        # print(" - ", i, cnt)
    print(ans)
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1