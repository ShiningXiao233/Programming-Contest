def gcd(a : int, b : int):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a : int, b : int):
    return a * b // gcd(a, b)


def sol():
    s = input()
    t = input()
    st = lcm(len(s), len(t))
    s = s * (st // len(s))
    t = t * (st // len(t))
    print(s if s == t else -1)
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1