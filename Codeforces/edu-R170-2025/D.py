
def get_num():
    return map(int, input().split())

def add(l: int, r: int, dif: list[int]):
    if l <= r:
        dif[l] += 1
        dif[r + 1] -= 1

def addp(dp, dif):
    for i in range(1, len(dif)):
        dif[i] += dif[i - 1]
    # print(dif)
    for i in range(len(dp)):
        dp[i] += dif[i]

def sol():
    n, m = get_num()
    a = list(get_num())
    cnt = 0
    dp = [-n for i in range(m + 1)]
    dp[0] = 0
    dif = [0 for i in range(m + 2)]
    for i, v in enumerate(a):
        if v == 0:
            cnt += 1
            addp(dp, dif)
            for i in range(len(dp) - 1, 0, -1):
                dp[i] = max(dp[i], dp[i - 1])
            dif = [0 for i in range(m + 2)]
            # print("-")
            # print(dp)
            # print(" --- ")
            pass
        elif v > 0:
            add(v, m, dif)
            pass
        elif v < 0:
            add(0, cnt + v, dif)
    addp(dp, dif)
    print(max(dp))

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1