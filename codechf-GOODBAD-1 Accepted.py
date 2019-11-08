
import string
for _ in range(int(input())):
    n, k = map(int,input().split())
    st = input()
    c1, c2 = 0, 0
    for i in range(len(st)):
        if st[i].islower():
            c2 += 1
        elif st[i].isupper():
            c1 += 1
    if c1<=k and c2<=k :
        print("both")
    elif c1<=k:
        print("chef")
    elif c2<=k:
        print("brother")
    else:
        print("none")

