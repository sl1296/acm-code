
#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int sum[800010];
void pushup(int rt){
    sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int q,int v,int l,int r,int rt){
    if(l==r&&l==q){
        sum[rt]=v;
        return;
    }
    int m=(l+r)>>1;
    if(q<=m)update(q,v,lson);else update(q,v,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)return sum[rt];
    int re=-2147483647;
    int m=(l+r)>>1;
    if(L<=m)re=max(re,query(L,R,lson));
    if(R>m)re=max(re,query(L,R,rson));
    return re;
}
int main(){
    int m,n;
    while(~scanf("%d%d",&n,&m)){
        build(1,n,1);
        for(int i=0;i<m;i++){
            char s[5];
            int x,y;
            scanf("%s%d%d",s,&x,&y);
            if(s[0]=='Q'){
                printf("%d\n",query(x,y,1,n,1));
            }else{
                update(x,y,1,n,1);
            }
        }
    }
    return 0;
}

