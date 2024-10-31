def sol():
    s = input()
    f = [0 for _ in range(26)]
    f2 = [[0 for _ in range(26)] for _ in range(26)]
    ans = 0
    for c in s:
        tc = ord(c) - ord('A')
        for cc in range(26):
            ans += f2[tc][cc]
        for cc in range(26):
            f2[cc][tc] += f[cc]
        f[tc] += 1

    print(ans)
    pass

if __name__ == '__main__':
    t = 1
    # t = int(input())
    while t > 0:
        sol()
        t -= 1