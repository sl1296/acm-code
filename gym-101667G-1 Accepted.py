
n, m = map(int, input().split())
L = list(map(int, input().split()))
U = list(map(int, input().split()))
a = []
for i in range(n):
    a.append([L[i*2+1], L[i*2+2], 0])
for i in range(m):
    a.append([U[i*2+1], U[i*2+2], 1])
a.sort()
yL, yU = L[0], U[0]
k, w, tmp = 0, 0, 0
flag, start = False, False
for i in range(n+m):
    if yL>yU:
        start = True
    if a[i][2]==0: 
        yL = a[i][1]
    else:
        yU = a[i][1]
    if yL<yU:
        if i+1<n+m:
            tmp += (yU-yL)*(a[i+1][0]-a[i][0])
        flag = True
    else:
        if start and flag:
            k += 1
            w += tmp
        tmp = 0
        flag = False
print(k, w)

