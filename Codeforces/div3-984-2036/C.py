def sol():
    s = input()
    s = [i for i in s]
    n = len(s)
    a = [0 for i in range(n)]
    ans = 0
    for i in range(n):
        if s[i:i+4] == ['1','1','0','0']:
            a[i] = 1
            ans += 1

    m = int(input())
    while m > 0:
        m -= 1
        x, v = map(int, input().split())
        x -= 1
        s[x] = str(v)
        for i in range(max(0, x - 3), x + 1):
            tp = (1 if s[i:i+4] == ['1','1','0','0'] else 0)
            ans += tp - a[i]
            a[i] = tp
        print('yes' if ans > 0 else 'no')

    

if __name__ == '__main__':
    # a = '44444'
    # a = [i for i in a]
    # print(a)
    # print(a[0:4] == ['4','4','4','4'])
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1