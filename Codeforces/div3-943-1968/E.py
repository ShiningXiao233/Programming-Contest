def sol():
    n = int(input())
    a = []
    a.append('1 1')
    a.append('1 2')
    for i in range(2, n):
        a.append(str(i + 1) + ' ' + str(i + 1))
    print('\n'.join(a))
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1