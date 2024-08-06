n = int(input())
a = list(map(int, input().split()))
b = min(*a)
p = n + 1
pre = -n
for i in range(n):
    if a[i] == b:
        p = min(p, i - pre)
        pre = i
print(p)
