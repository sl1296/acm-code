
with open('auxiliary.in','r') as f:
    n = int(f.read())
a = [0, 0, 1, 7, 4, 5, 9, 8]
dp = [-1 for i in range(n+1)]
dp[0] = 0
for i in range(1, n+1):
    for j in range(2, 8):
        if i-j>=0 and dp[i-j]!=-1:
            dp[i] = max(dp[i], dp[i-j]+a[j])
with open('auxiliary.out','w') as f:
    print(dp[n], file=f)

