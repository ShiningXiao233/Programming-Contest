def sol():
    n, k = map(int, input().split())
    a = [str(i) for i in range(1, 2 * k - n)] + [str(i) for i in range(k, 2 * k - n - 1, -1)]
    print(' '.join(a))
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1