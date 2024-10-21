def sol():
    s = input()
    t = input()
    slen, tlen = len(s), len(t)
    i = 0
    while i < slen and i < tlen and s[i] == t[i]:
        i += 1
    print(slen + tlen - (i - 1 if i > 1 else 0))
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1