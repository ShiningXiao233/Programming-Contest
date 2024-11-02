def sol():
    n = int(input())
    a = list(map(int, input().split()))
    flag = True
    for i in range(1, n):
        if abs(a[i] - a[i - 1]) not in [5, 7]:
            flag = False 
    print("yes" if flag else "no")
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1