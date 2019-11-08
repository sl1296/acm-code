

for _ in range(int(input())):
    n, E = map(int, input().split())
    x = list(map(int, input().split()))
    y = [[x[i],i] for i in range(n)]
    if n==1:
        if x[0]==E:
            print(1)
        else:
            print(-1)
    else:
        y.sort()
        if y[0][0]<=E and y[-1][0]>=E:
            ans = [[0,e[1]] for e in y]
            if y[0][0]==y[-1][0]:
                ans[-1][0]=1
            else:
                a = (E-y[-1][0])/(y[0][0]-y[-1][0])
                b = 1 - a
                ans[0][0], ans[-1][0] = a, b
            ans.sort(key = lambda e:e[1])
            print(' '.join(str(e[0]) for e in ans))
        else:
            print(-1)

