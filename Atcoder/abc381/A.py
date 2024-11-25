def sol():
    input()
    a = input().split('/')
    if len(a) == 2 and len(a[0]) == len(a[1]):
        n = len(a[0])
        a1 = '1' * n
        a2 = '2' * n
        if a1 == a[0] and a2 == a[1]:
            print('Yes')
        else:
            print('No')
    else:
        print('No')
    pass

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1