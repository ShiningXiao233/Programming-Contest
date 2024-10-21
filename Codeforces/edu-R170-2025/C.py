from collections import Counter

import sys
input=lambda:sys.stdin.readline()

def sol():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    # print(a)
    ans = 0
    l = 0
    sum = 0
    oldkey = -100
    difcnt = 0
    for r, v in enumerate(a):
        if oldkey + 1 >= v:
            if oldkey != v:
                difcnt += 1
                oldkey = v
        else:
            l, sum, difcnt, oldkey = r, 0, 1, v
        sum += 1
        # print(r, l,v, difcnt, oldkey, sum, k)
        while l <= r and difcnt > k:
            sum -= 1
            if l == r:
                difcnt -= 1
                oldkey = -1
            elif a[l] != a[l + 1]:
                difcnt -= 1
            l += 1
        ans = max(ans, sum)

    print(ans)
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1