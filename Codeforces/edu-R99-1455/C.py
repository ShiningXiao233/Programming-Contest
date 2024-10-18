def sol():
    a, b = map(int, input().split())
    print(a - 1, b)
    

if __name__ == '__main__':
    T = int(input())
    while T > 0:
        T -= 1
        sol()