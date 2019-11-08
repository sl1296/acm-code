
import bisect
for ca in range(int(input())):
    n, z = map(int, input().split(' '))
    ans, sx, sy = z**n, 0, 0
    a = [i**n for i in range(z)]
    for i in range(z-1, 1, -1):
        res = z**n - i**n
        pos = bisect.bisect_left(a, res)
        if pos<i and pos**n==res:
            ans, sy, sx = 0, i, pos
        else:
            if pos<i and abs(pos**n - res) < ans:
                ans, sy, sx = abs(pos**n - res), i, pos
            if pos-1>0 and abs((pos-1)**n - res) < ans:
                ans, sy, sx = abs((pos-1)**n - res), i, pos-1
    print(sx, sy, ans)

