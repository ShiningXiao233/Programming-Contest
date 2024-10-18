def sol():
    n = int(input())
    a = list(map(int, input().split()))
    a1 = a[:]
    a2 = a[:]
    sum1 = 0
    sum2 = 0
    for i in range(n):
        if i % 2 == 0:
            a1[i] = 1
            sum1 += a[i] - a1[i]
        else:
            a2[i] = 1
            sum2 += a[i] - a2[i]
    
    if 2 * sum1 <= sum(a):
        print(' '.join(list(map(str, a1))))
    else:
        print(' '.join(list(map(str, a2))))
    
    

if __name__ == '__main__':
    T = int(input())
    while T > 0:
        sol()
        T -= 1