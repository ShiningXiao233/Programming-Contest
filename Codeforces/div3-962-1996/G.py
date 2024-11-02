# 根据环的思想，肯定需要考虑的是破环成链
# 当断开一条边，也就相当于对所有的关系都定好了方向，这时候需要考虑哪些边没有被覆盖过。
# 1. 考虑使用区间覆盖线段树，记录被覆盖数量为0的边。
# 2. 考虑hash，是差分hash，当一个区间被覆盖时，对这个区间都异或同一个值。然后记录值为0的边。
#  继续考虑hash，我们将链延长2倍，根据双指针的做法记录区间出现最多的数，
#  继续思考会发现，其实在n点的异或值就是0，也就是说，双倍链中的每个长度为n的区间的值分布是一样的。所以直接记录出现最多的数即可。


import random

def rrd():
    return random.randint(1, 65535) + 65536 * random.randint(1, 65535) + 65535 * 65536 * random.randint(1, 65535)

def sol():
    n, m = map(int, input().split())
    a = [0 for _ in range(n)]
    while m > 0:
        m -= 1
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        p = rrd()
        a[x] ^= p
        a[y] ^= p
    p = dict()

    for i in range(1, n):
        a[i] ^= a[i - 1]
    
    for i in a:
        if i not in p:
            p[i] = 1
        else: p[i] += 1
    
    print(n - max(p.values()))
    pass

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        sol()