def sol():
    n = int(input())
    a = list(map(int, input().split()))
    mp = set()
    mp.add(0)
    sum = 0
    ans = 0
    for v in a:
        sum += v
        if sum in mp:
            ans += 1
            sum = 0
            mp.clear()
        mp.add(sum)
    print(ans)
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1