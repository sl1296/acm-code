
def calc(n, a):
    global fac
    ans = 0
    se = set()
    for i in range(n):
        for j in range(1, a[i]):
            if j not in se:
                ans += fac[n-i-1]
        if a[i] not in se:
            se.add(a[i])
        else:
            break
    return ans

with open("permutations.in","r") as f:
    n = int(f.readline())
    a = list(map(int,f.readline().split()))
    b = list(map(int,f.readline().split()))
fac = [0 for i in range(n+1)]
fac[0] = 1
for i in range(1, n+1):
    fac[i] = fac[i-1] * i
ans = calc(n, b)-calc(n,a)
se = set()
flag = True
for i in range(n):
    if b[i] not in se:
        se.add(b[i])
    else:
        flag = False
        break
if flag:
    ans += 1
with open("permutations.out","w") as f:
    print(ans, file=f)


