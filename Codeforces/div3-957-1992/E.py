def sol():
    n = int(input())
    ans = []
    for a in range(1, 10000 + 1):
        lenn = len(str(n))
        for b in range(max(1, lenn * a - 8), lenn * a, 1):
            if b > 10000 or b > a * n: break
            tmp = n * a - b
            tmplen = lenn * a - b
            aa = str(n)
            anum = ''.join(aa[i % lenn] for i in range(tmplen))
            anum = int(anum)
            # print(a, b, tmp, anum)
            if anum == tmp:
                ans.append(str(a) + ' ' + str(b))
    print(len(ans))
    print('\n'.join(ans))


if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        sol()