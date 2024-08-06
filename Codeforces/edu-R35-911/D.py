n = int(input())

p = list(map(int, input().split()))

m = int(input())

ans = 0

for i in range(n):
    for j in range(i, n):
        if p[i] > p[j]:
            ans += 1

while m > 0:
    m -= 1
    l, r = map(int, input().split())
    k = (r - l + 1) // 2
    ans += k
    print("odd" if ans % 2 == 1 else "even")