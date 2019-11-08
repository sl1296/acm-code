
mod = int(1e9+7)
ans = [0,1]
tmp = 1
for i in range(2,100001):
    tmp = tmp*2 % mod
    ans.append(ans[i-1]*((tmp-1+mod)%mod)%mod)
for _ in range(int(input())):
    n = int(input())
    print(ans[n])

