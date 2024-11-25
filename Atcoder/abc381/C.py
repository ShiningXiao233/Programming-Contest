def sol():
    input()
    a = input().split('/')
    ans = 0
    for i in range(1, len(a)):
        n1 = len(a[i - 1])
        n2 = len(a[i])
        cnt = 0
        for x in range(min(n1, n2)):
            if a[i][x] == '2' and a[i - 1][-x - 1] == '1':
                cnt += 1
            else:
                break
        ans = max(ans, cnt)
    print(ans * 2 + 1)

if __name__ == '__main__':
    t = 1
#     t = int(input())
    while t > 0:
        sol()
        t -= 1