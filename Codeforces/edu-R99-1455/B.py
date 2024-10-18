def sol():
    n = int(input())
    i = 1
    while i * (i + 1) // 2 < n:
        i += 1
    if i * (i + 1) // 2 - n == 1:
        i += 1
    print(i)
    pass

if __name__ == '__main__':
    T = int(input())
    while T > 0:
        T -= 1
        sol()