
def C(n,k):
    global fac
    return fac[n]//(fac[k]*fac[n-k])

fac = [0 for i in range(301)]
fac[0] = 1
for i in range(1,301):
    fac[i] = fac[i-1]*i
ca = int(input())
for cas in range(ca):
    n, k, d = map(int, input().split())
    ans = C(n,k)
    st = ''
    while ans>0:
        st = str(ans%d) + st
        ans //= d
    print(st)

