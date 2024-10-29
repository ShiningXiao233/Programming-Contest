
MOD = 1000000007

def qp(x : int, q : int = MOD - 2):
    res = 1
    while q > 0:
        if q & 1:
            res = res * x % MOD
        x = x * x % MOD
        q >>= 1
    return res

def sol():
    n = int(input())
    a = list(map(int, input().split()))
    suma = sum(a)
    res = 0
    for i in a:
        res += i * (suma - i) % MOD * qp(n - 1) % MOD
    res *= qp(n)
    res %= MOD
    print(res)

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        sol()