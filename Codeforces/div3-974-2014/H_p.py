def sol():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    xor = [0]
    for i in a:
        xor.append(xor[-1] ^ hash(str(i)))
    while q > 0:
        l, r = map(int, input().split())
        if (xor[r] ^ xor[l - 1]) == 0:
            print('yes')
        else:
            print('no')
        q -= 1
    pass

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        sol()
        t -= 1