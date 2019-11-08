
#include<cstdio>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[200010];
void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
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
        sum[rt]+=v;
        return;
    }
    int m=(l+r)>>1;
    if(q<=m)update(q,v,lson);else update(q,v,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)return sum[rt];
    int re=0;
    int m=(l+r)>>1;
    if(L<=m)re+=query(L,R,lson);
    if(m<R)re+=query(L,R,rson);
    return re;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        build(1,n,1);
        printf("Case %d:\n",z);
        while(1){
            char s[10];
            scanf("%s",s);
            if(strcmp(s,"End")==0)break;
            int x,y;
            scanf("%d%d",&x,&y);
            if(strcmp(s,"Add")==0){
                update(x,y,1,n,1);
            }else if(strcmp(s,"Sub")==0){
                update(x,-y,1,n,1);
            }else{
                printf("%d\n",query(x,y,1,n,1));
            }
        }
    }
    return 0;
}

