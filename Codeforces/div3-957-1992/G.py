class xzlMath( object ):
    f = None
    rf = None
    N = 5000
    MOD = 1000000007

    @staticmethod
    def lcm(a : int, b : int):
        return a * b // xzlMath.gcd(a, b)
    
    @staticmethod
    def gcd(a : int, b : int):
        if b == 0:
            return a
        else:
            return xzlMath.gcd(b, a % b)
        
    @staticmethod
    def qp(x: int, q: int = None):
        if q is None: q = xzlMath.MOD - 2
        MOD = xzlMath.MOD
        res = 1
        while q > 0:
            if (q & 1) > 0:
                res = res * x % MOD
            q >>= 1
            x = x * x % MOD
        return res

    @staticmethod
    def C(n: int, m: int):
        if n < 0 or m > n or m < 0:
            return 0
        if xzlMath.f is None:
            xzlMath.f = [1 for _ in range(xzlMath.N + 1)]
            xzlMath.rf = [1 for _ in range(xzlMath.N + 1)]
            for i in range(1, xzlMath.N + 1):
                xzlMath.f[i] = xzlMath.f[i - 1] * i % xzlMath.MOD
            xzlMath.rf[xzlMath.N] = xzlMath.qp(xzlMath.f[xzlMath.N])
            for i in range(xzlMath.N, 0, -1):
                xzlMath.rf[i - 1] = xzlMath.rf[i] * i % xzlMath.MOD
        f = xzlMath.f
        rf = xzlMath.rf
        MOD = xzlMath.MOD
        return f[n] * rf[m] % MOD * rf[n - m] % MOD


def sol():
    n = int(input())
    ans = 0
    for i in range(1, 2 * n + 2):
        for b in range(n + 1):
            pre_in = i - 1 - b
            if pre_in < 0: break
            ls_black = max(0, n - i)
            ls_in = b - pre_in
            ans += xzlMath.C(min(n, i - 1), pre_in) * xzlMath.C(ls_black, ls_in) * i % xzlMath.MOD
            ans %= xzlMath.MOD
    
    print(ans)
    pass


if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        sol()