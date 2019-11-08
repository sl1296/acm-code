
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 7e3;
typedef long long LL;

LL N, Ans, Fac[MAXN], Pri[MAXN];
int tot, cnt;

void Prepare(LL N) {
    for (LL i = 1; i * i < N; i ++) {
        if (N % i != 0) continue;
        Fac[++ tot] = i;
        if (1ll * i * i == N) continue;
        Fac[++ tot] = N / i;
    }
}

bool IsPrime(LL Now) {
    for (LL i = 2; i * i <= Now; i ++) 
        if (Now % i == 0) return 0;
    return 1;
}

void GetPri() {
    for (int i = 1; i <= tot; i ++) 
        if (IsPrime(Fac[i] + 1)) Pri[++ cnt] = Fac[i] + 1;
}

bool cmp(LL a, LL b) { return a > b;}

bool Check(LL Num, LL Now) {
    if (Now == 1) return 1;
    if (Now % Pri[Num] == 0) return Check(Num, Now / Pri[Num]);
    return 0;
}

void Dfs(int Num, LL Now, LL S) {
    if (Num > cnt || S > Ans || Now == 1) return;
    if (Now % (Pri[Num] - 1) != 0) {
        Dfs(Num + 1, Now, S);
        return;
    }
    if (Now % (Pri[Num] - 1) == 0 && Check(Num, Now / (Pri[Num] - 1))) 
        Ans = min(Ans, S / (Pri[Num] - 1) * Pri[Num]);
    LL Ord = (Pri[Num] - 1);
    for (; Now % Ord == 0; Ord *= Pri[Num]) 
        Dfs(Num + 1, Now / Ord, S / (Pri[Num] - 1) * Pri[Num]);
    Dfs(Num + 1, Now, S);
}

void Solve(LL N) {
    Ans = (N == 1) ? N : N * 10;
    tot = cnt = 0;
    Prepare(N);
    GetPri();
    sort(Pri + 1, Pri + 1 + cnt, cmp);
    Dfs(1, N, N);
}

int main () {
    int Test;
    scanf("%d", &Test);
    for (; Test; Test --) {
        scanf("%lld", &N);
        Solve(N);
        printf("%lld\n", Ans);
    }
}

