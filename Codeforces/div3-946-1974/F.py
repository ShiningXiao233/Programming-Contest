def sol():
    a, b, n, m = map(int, input().split())
    st = set()
    xy = []
    yx = []
    while n > 0:
        n -= 1
        x, y = map(int, input().split())
        xy.append((x, y))
        yx.append((y, x))
        st.add((x, y))
    
    xy.sort()
    yx.sort()
    # print(xy, yx)
    sx, sy, ex, ey = 1, 1, a, b
    xyl, xyr = 0, len(xy) - 1
    yxl, yxr = 0, len(xy) - 1
    ans = [0, 0]
    id = 0
    while m > 0:
        m -= 1
        opt, c = input().split()
        c = int(c)
        now = 0
        if opt == 'U':
            sx += c

            while xyl <= xyr:
                if xy[xyl][0] < sx:
                    if xy[xyl] in st:
                        now += 1
                        st.remove(xy[xyl])
                else:
                    break
                xyl += 1
        elif opt == 'D':
            ex -= c

            while xyl <= xyr:
                if xy[xyr][0] > ex:
                    if xy[xyr] in st:
                        now += 1
                        st.remove(xy[xyr])
                else:
                    break
                xyr -= 1
        elif opt == 'L':
            sy += c

            while yxl <= yxr:
                if yx[yxl][0] < sy:
                    if (yx[yxl][1],yx[yxl][0])  in st:
                        now += 1
                        st.remove((yx[yxl][1],yx[yxl][0]))
                else:
                    break
                yxl += 1
        elif opt == 'R':
            ey -= c

            while yxl <= yxr:
                if yx[yxr][0] > ey:
                    if (yx[yxr][1], yx[yxr][0]) in st:
                        now += 1
                        st.remove((yx[yxr][1], yx[yxr][0]))
                else:
                    break
                yxr -= 1
        ans[id] += now
        id ^= 1

    print(ans[0], ans[1])

    pass

if __name__ == '__main__':
    t = 1
    t = int(input())
    while t > 0:
        sol()
        t -= 1
        # break