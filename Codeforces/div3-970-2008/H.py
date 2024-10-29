
def sol():
    n, m = map(int,input().split())
    a = list(map(int, input().split()))
    cnt = [0 for _ in range(n + 1)]
    for _ in a:
        cnt[_] += 1
    for _ in range(1, n + 1):
        cnt[_] += cnt[_ - 1]
    ans = [0 for _ in range(n + 1)]

    def get(x, b):
        res = cnt[b]
        for i in range(x, n + 1, x):
            res += (cnt[(n if i + b > n else i + b)] - cnt[i - 1])
        return res
    # print(cnt)
    # print(get(1, 0))

    for i in range(1, n + 1):
        l, r = 0, i
        while l < r:
            mid = (l + r) >> 1
            if get(i, mid) > n // 2:
                r = mid
            else: l = mid + 1
        ans[i] = l
    for i in range(m):
        x = int(input())
        print(ans[x], end=' ')
    print()

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        sol()