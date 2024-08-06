
def sol():
    a = list(map(int, input().split()))
    a.sort()
    if (a[0] == 1) or (a[0] == 2 and a[1] == 2) or (a[0] == a[2] and a[0] == 3) or (a == [2, 4, 4]):
        print("YES")
    else:
        print("NO")
    
if __name__ == '__main__':
    sol()