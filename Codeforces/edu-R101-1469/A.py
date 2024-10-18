n = int(input())

def sol():
    s = input()
    if len(s) % 2 == 1:
        print("NO")
    else:
        a_l = s.find("(")
        a_r = s.find(")")
        if a_l < a_r:
            print("YES")
        else:
            if a_r == 0 or a_l == len(s) - 1:
                print("NO")
            else:
                print("YES") 


for _ in range(n):
    sol()