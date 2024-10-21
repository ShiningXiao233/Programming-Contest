def qp(x, q):
    global MOD
    res = 1
    while q > 0:
        if (q & 1) > 0:
            res = res * x % MOD
        q >>= 1
        x = x * x % MOD
    return res
    
MOD = 1000000007

def sol():
    input()
    n = list(map(int, input().split()))
    k = list(map(int, input().split()))
    for a, b in zip(n, k):
        print(1 if a == b else qp(2, b))
    pass

if __name__ == '__main__':
    t = 1
    # t = int(input())
    while t > 0:
        sol()
        t -= 1