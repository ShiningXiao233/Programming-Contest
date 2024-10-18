def sol():
    a, b, c = map(int, input().split())
    if (a + b + c) % 9 == 0 and min(a, b, c) >= (a + b + c) / 9:
        print("YES")
    else:
        print("NO")
    pass

if __name__ == '__main__':
    T = int(input())
    while T > 0:
        sol()
        T -= 1