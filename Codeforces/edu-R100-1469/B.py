
def sol():
    n = int(input())
    r = list(map(int, input().split()))
    for i in range(1, n):
        r[i] += r[i - 1]
    ans = max(max(r), 0)
    n = int(input())
    r = list(map(int, input().split()))
    for i in range(1, n):
        r[i] += r[i - 1]
    ans += max(max(r), 0)
    print(ans)


if __name__ == '__main__':
    T = int(input())
    while T > 0:
        sol()
        T -= 1