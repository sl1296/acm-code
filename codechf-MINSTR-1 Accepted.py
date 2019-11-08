

for _ in range(int(input())):
    n = int(input())
    a = b = k1 = k2 = 0
    st = input().split()
    for i in range(n):
        if st[i]=='a' or st[i]=='aa':
            a = 1
        elif st[i]=='b' or st[i]=='bb':
            b = 1
        elif st[i]=='ab':
            k1 += 1
        else:
            k2 += 1
    if k1!=0 or k2!=0:
        if k1==k2:
            print(2*k1+1)
        else:
            print(2*max(k1,k2))
    else:
        print(a+b)
        

