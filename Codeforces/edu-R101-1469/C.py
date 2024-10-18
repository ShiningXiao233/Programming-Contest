
def sol():
    n, k = map(int, input().split())
    h = list(map(int, input().split()))
    Min = h[0]
    Max = h[0]
    flag = True
    for i in range(1, n):
        # print(Min, Max)
        Min, Max = max(Min - k + 1, h[i]), min(Max + k - 1, h[i] + k - 1)
        if Max < Min:
            flag = False
    if h[n - 1] < Min or h[n - 1] > Max:
        flag = False
    print("YES" if flag else "NO")


if __name__ == '__main__':
    T = int(input())
    while T > 0:
        sol()
        T -= 1