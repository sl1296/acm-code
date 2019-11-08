
for _ in range(int(input())):
    n = int(input())
    print(1, 1)
    a1 = int(input())
    k1 = 1
    l, r = 2, n
    while l<=r:
        mid = l+r>>1
        print(1, mid)
        x = int(input())
        if x==a1:
            l = mid+1
        else:
            r, k1 = mid-1, mid-1
    print(1, n)
    an = int(input())
    print(1, n-k1+1)
    ak = int(input())
    if an!=ak:
        print(2, an)
    else:
        print(1, n-k1)
        ak1 = int(input())
        if ak1==ak:
            print(2, a1)
        else:
            l, r = 2, (n-1)//k1
            ans = 0
            while l<=r:
                mid = l+r>>1
                s, t = (mid-1)*k1+1, mid*k1
                print(1, s)
                x1 = int(input())
                print(1, t)
                x2 = int(input())
                if x1==x2:
                    l = mid+1
                else:
                    r, ans = mid-1, x1
            print(2, ans)

