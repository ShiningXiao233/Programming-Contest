
def sol():
    n, k = map(int,input().split())
    a = list(map(int, input().split()))
    if n == 1:
        print(k - 1 if k - 1 < a[0] else k)
        return
    G = 0
    def gcd(a, b):
        return a if b == 0 else gcd(b, a % b)
    for i in a:
        G = gcd(G, i)
    if (n - 1) * (G - 1) < k:
        k -= (n - 1) * (G - 1)
        print((n - 1) * G + k)
    else:
        k += (k - 1) // (G - 1)
        print(k)


if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        sol()