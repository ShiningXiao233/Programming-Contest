def sol():
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    def chk(a):
        pre = -1
        for i in a:
            if pre > i:
                return False
            else:
                pre = i;
        return True
    if chk(a):
        print(0)
    else:
        ans = 0
        for i in range(n):
            if a[i] > x:
                a[i], x = x, a[i]
                ans += 1
            if chk(a):
                print(ans)
                return
        print(-1)    
        


if __name__ == '__main__':
    T = int(input())
    while T > 0:
        T -= 1
        sol()