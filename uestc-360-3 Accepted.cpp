
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls (o<<1)
#define rs (o<<1|1)
#define lson ls, L, M
#define rson rs, M+1, R
using namespace std;
const int N = 100005;
int arr[N];
int n, q;

int lv[N<<2], rv[N<<2], addv[N<<2];
int longest[N<<2], suml[N<<2], sumr[N<<2];

void pushUp(int o, int L, int R) {
    int M = (L+R)/2;
    int lenL = M - L + 1, lenR = R - M;

    suml[o] = suml[ls], sumr[o] = sumr[rs];
    lv[o] = lv[ls], rv[o] = rv[rs];
    longest[o] = max(longest[ls], longest[rs]);

    int ml = rv[ls], mr = lv[rs];
    if(ml < mr) {
        if(suml[ls] == lenL)
            suml[o] += suml[rs];
        if(sumr[rs] == lenR)
            sumr[o] += sumr[ls];
        longest[o] = max(longest[o], sumr[ls] + suml[rs]);
    }
}

void pushDown(int o) {
    if(addv[o]) {
        addv[ls] += addv[o], addv[rs] += addv[o];
        lv[ls] += addv[o], lv[rs] += addv[o];
        rv[ls] += addv[o], rv[rs] += addv[o];
        addv[o] = 0;
    }
}

void build(int o, int L, int R) {
    addv[o] = 0;
    if(L == R) {
        lv[o] = rv[o] = arr[L];
        longest[o] = suml[o] = sumr[o] = 1;
        return ;
    }
    int M = (L+R)/2;
    build(lson);
    build(rson);
    pushUp(o, L, R);
}

void modify(int o, int L, int R, int ql, int qr, int val) {
    if(ql <= L && R <= qr) {
        lv[o] += val, rv[o] += val;
        addv[o] += val;
        return ;
    }
    pushDown(o);
    int M = (L+R)/2;
    if(ql <= M) modify(lson, ql, qr, val);
    if(qr > M) modify(rson, ql, qr, val);
    pushUp(o, L, R);
}

int query(int o, int L, int R, int ql, int qr) {
    if(ql <= L && R <= qr) return longest[o];

    pushDown(o);
    int M = (L+R)/2, ret = -1;
    if(ql <= M) ret = max(ret, query(lson, ql, qr));
    if(qr > M) ret = max(ret, query(rson, ql, qr));

    int rr, ll;
    int ml = rv[ls], mr = lv[rs];
    if(ml < mr) {
        rr = min(qr - M, suml[rs]);
        ll = min(M - ql + 1, sumr[ls]);
        ret = max(ret, rr + ll);
    }
    return ret;
}

char cmd[5];
int main() {
  //  freopen("in.txt","r",stdin);
  //  freopen("outans.txt","w+",stdout);
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        build(1, 1, n);
        int ql, qr, val;

        printf("Case #%d:\n", cas++);
        while(q--) {
            scanf("%s", cmd);
            if(cmd[0] == 'q') {
                scanf("%d%d", &ql, &qr);
                int ans = query(1, 1, n, ql, qr);
                printf("%d\n", ans);
            }else {
                scanf("%d%d%d", &ql, &qr, &val);
                modify(1, 1, n, ql, qr, val);
            }
        }
    }
    return 0;
}

