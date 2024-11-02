a = '123'
print(a)
print(a[0:])
print(''.join(a[_ % 3] for _ in range(0, 8)))