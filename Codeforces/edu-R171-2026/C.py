def sol():
    n = input()
    s = input()
    n = len(s)
    s = ' ' + s
    l, r = 0, n
    ans = 0

    def chk(x: int):
        cnt = 0
        p = 0
        for i in range(n, 0, -1):
            if s[i] == '1': cnt += 1; p += 1
            elif cnt > 0: cnt -= 1
            # print(i, p, cnt)
            if p == x:
                # print(i)
                if i - 1 >= cnt:
                    return True
                else: return False
        return False
    # print(chk(3))
    while l < r:
        mid = (l + r) // 2
        if chk(mid):
            ans = mid
            l = mid + 1
        else:
            r = mid
    # print(ans, '-')
    cnt = 0
    for i in range(n, 0, -1):
        if s[i] == '1' and ans > 0:
            ans -= 1
            cnt += i
            # print(i, '+')
    
    ans = sum(i for i in range(1, n + 1)) - cnt
    print(ans)
    pass

if __name__ == '__main__':
    t = int(input())
    while t > 0:
        t -= 1
        sol()