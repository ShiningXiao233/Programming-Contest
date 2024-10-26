def sol():
    n = int(input())
    print("Kosuke" if n % 2 == 1 else "Sakurako")
    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1