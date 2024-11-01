
def sol():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    l, r = 0, max(a) + 1
    ans = 0
    
    def chk(x):
        res = 0
        for i in range(n):
            if a[i] > x:
                res += (a[i] - x + b[i] - 1) // b[i] 
        return res

    while l < r:
        mid = (l + r) // 2
        if chk(mid) >= k:
            ans = mid
            l = mid + 1
        else:
            r = mid

    res = 0
    tmp = 0
    for i in range(n):
        if a[i] > ans:
            x = (a[i] - ans + b[i] - 1) // b[i]
            if a[i] - (x - 1) * b[i] == ans + 1:
                tmp += 1
                x -= 1
            res += (a[i] + a[i] - (x - 1) * b[i]) * x // 2
            k -= x
    res += min(k, tmp) * (ans + 1)
    print(res)

    pass

if __name__ == '__main__':
    T = int(input())
    while T > 0:
        T -= 1
        sol()