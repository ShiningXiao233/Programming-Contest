N = 1000

def gcd(a : int, b : int):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a : int, b : int):
    return a * b // gcd(a, b)

Comb = [[0 for _ in range(N)] for _ in range(N)]

def comb_pre(n : int):
    global MOD
    Comb[0][0] = 1
    for i in range(1, n + 1):
        Comb[i][0] = 1
        for j in range(1, i + 1):
            Comb[i][j] = (Comb[i - 1][j] + Comb[i - 1][j - 1]) % MOD

def comb(n: int, m : int):
    if n < 0 or m > n or m < 0:
        return 0
    return Comb[n][m]

def qp(x, q):
    global MOD
    res = 1
    while q > 0:
        if (q & 1) > 0:
            res = res * x % MOD
        q >>= 1
        x = x * x % MOD
    return res
    