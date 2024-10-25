def sol():
    a = input()
    a = a + '1'
    dp = [0 for i in range(len(a) + 4)]
    dp[0] = 1
    dp[1] = 1
    for i in range(2, len(a)):
        if a[i] >= a[i - 1]:
            dp[i] |= dp[i - 1]
        if a[i] >= a[i - 2]:
            dp[i] |= dp[i - 2]

    print('YES' if dp[len(a) - 1] == 1 else 'NO')

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        sol()
        t -= 1