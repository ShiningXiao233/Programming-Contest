def sol():
    l, r, k = map(int, input().split())
    print(max(0, r // k - l + 1))
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1