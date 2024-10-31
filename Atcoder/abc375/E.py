
def sol():
    n = int(input())
    a = [0 for _ in range(n)]
    b = [0 for _ in range(n)]

    zsum = 0
    for i in range(n):
        a[i], b[i] = map(int, input().split())
        zsum += b[i]
    # print(zsum)
    if zsum % 3 > 0:
        print(-1)
        return
    K = zsum // 3
    dp = [[n for _ in range(K + 1)] for _ in range(K + 1)]
    dp[0][0] = 0
    for i in range(n):
        B, A = a[i], b[i]
        tmp = [[n for _ in range(K + 1)] for _ in range(K + 1)]
        for i in range(K + 1):
            for j in range(K + 1):
                if B == 1:
                    # 不改变
                    if i + A <= K:
                        tmp[i + A][j] = min(tmp[i + A][j], dp[i][j])
                    # 改变到2
                    if j + A <= K:
                        tmp[i][j + A] = min(tmp[i][j + A], dp[i][j] + 1)
                    # 改变到3
                    tmp[i][j] = min(tmp[i][j], dp[i][j] + 1)

                    pass
                elif B == 2:
                    # 到1
                    if i + A <= K:
                        tmp[i + A][j] = min(tmp[i + A][j], dp[i][j] + 1)
                    # 改变到2
                    if j + A <= K:
                        tmp[i][j + A] = min(tmp[i][j + A], dp[i][j])
                    # 改变到3
                    tmp[i][j] = min(tmp[i][j], dp[i][j] + 1)
                    pass
                else:
                    # 到1
                    if i + A <= K:
                        tmp[i + A][j] = min(tmp[i + A][j], dp[i][j] + 1)
                    # 改变到2
                    if j + A <= K:
                        tmp[i][j + A] = min(tmp[i][j + A], dp[i][j] + 1)
                    # 改变到3
                    tmp[i][j] = min(tmp[i][j], dp[i][j])
                    pass
        dp = tmp
    print(dp[K][K] if dp[K][K] < n else -1)
    return
    

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1