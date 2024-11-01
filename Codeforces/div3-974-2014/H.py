def sol():
    n, q = map(int, input().split())
    sum = [0 for _ in range(n + 1)]
    a = list(map(int, input().split()))
    for i in range(1, n + 1):
        sum[i] = sum[i - 1]
        sum[i] ^= (1 << a[i - 1])
    while q > 0:
        l, r = map(int, input().split())
        if (sum[r] ^ sum[l - 1]) == 0:
            print('yes')
        else:
            print('no')
        q -= 1
    pass

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        sol()
        t -= 1