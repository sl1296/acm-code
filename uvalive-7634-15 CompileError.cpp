
/*
code.cpp: In function ¡®int main()¡¯:
code.cpp:49:17: error: ISO C++ forbids comparison between pointer and integer [-fpermissive]
     if(t1<0||t1>100010)while(1);
                 ^~~~~~
code.cpp:50:17: error: ISO C++ forbids comparison between pointer and integer [-fpermissive]
     if(t2<0||t2>100010)while(1);
                 ^~~~~~
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod = 342307123;
const int maxn = 100010;
const int maxg = 10010;
const int a[5] = {0, 1, 3, 2};
const int b[5] = {0, 3, 2, 1};
char s[maxn], t1[maxg], t2[maxg];
LL cnt[5];
int dp[5][maxg];
inline int getVal(int x) {
  if (s[x + 1] == 0) {
    return (s[x] - '0') << 1;
  }
  return ((s[x] - '0') << 1) + s[x + 1] - '0';
}
LL pow_mod(LL x, int k) {
  LL res = 1, cur = x;
  while (k) {
    if (k & 1)  {
      res = (res * cur) % mod;
    }
    cur = (cur * cur) % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  dp[1][0] = 0, dp[2][0] = 1, dp[3][0] = 1;
  for (int i = 1; i < maxg; ++i) {
    for (int j = 1; j < 4; ++j) {
      dp[j][i] = (dp[a[j]][i - 1] + dp[b[j]][i - 1]) % mod;
    }
  }
  int t, tt = 0;
  scanf("%d", &t);
  while (t--) {
    int g, p1, p2;
    scanf("%s%d", s, &g);
    --g;
    if (g == 0) {
      scanf("%d%d", &p1, &p2);
    } else {
      scanf("%d%s%d%s", &p1, t1, &p2, t2);
    }
    if(t1<0||t1>100010)while(1);
    if(t2<0||t2>100010)while(1);
    memset(cnt, 0, sizeof cnt);
    for (int i = p1; i < p2; ++i) {
      ++cnt[getVal(i)];
    }
    LL ans = 0;
    for (int i = 0; i < 4; ++i) {
      ans = (ans + cnt[i] * dp[i][g]) % mod;
    }
    int st1 = getVal(p1), st2 = getVal(p2);
    LL sum = (pow_mod(2, g) * (p2 - p1) + 1)% mod;
    for (int i = 0; i < g; ++i) {
      if (t1[i] == 'R') {
        ans = (ans - dp[a[st1]][g - i - 1] + mod) % mod;
        sum = (sum - pow_mod(2, g - i - 1) + mod) % mod;
        st1 = b[st1];
      } else {
        st1 = a[st1];
      }
      if (t2[i] == 'R') {
        ans = (ans + dp[a[st2]][g - i - 1]) % mod;
        sum = (sum + pow_mod(2, g - i - 1)) % mod;
        st2 = b[st2];
      } else {
        st2 = a[st2];
      }
    }
    ans += a[st2] >> 1;
    printf("Case %d: %d %d\n", ++tt, int((sum - ans + mod) % mod), int(ans));
  }
  return 0;
}

