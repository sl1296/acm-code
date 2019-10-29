
n, s = map(int,input().split())
a = []
for i in range(n):
    st = input().split()
    a.append([st[0],int(st[1])])
a.sort(key=lambda e:e[1],reverse=True)
ans = []
for e in a:
    if s>=e[1]:
        s -= e[1]
        ans.append(e[0])
if s==0:
    print(len(ans))
    for e in ans:
        print(e)
else:
    print(0)

