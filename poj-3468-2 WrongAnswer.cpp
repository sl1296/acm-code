
#include<cstdio>
#define ll long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
ll tree[400010],add[400010];
void pushup(int l,int r,int mid,int rt){
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
    tree[rt]+=add[rt<<1]*(mid-l+1);
    tree[rt]+=add[rt<<1|1]*(r-mid);
}
void pushdown(int l,int r,int rt){
    add[rt<<1]=add[rt<<1|1]=add[rt];
    tree[rt]+=add[rt]*(r-l+1);
    add[rt]=0;
}
void build(int l,int r,int rt){
    add[rt]=0;
    if(l==r){
        scanf("%lld",&tree[rt]);
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(l,r,mid,rt);
}
void update(int from,int to,int v,int l,int r,int rt){
    if(from<=l&&to>=r){
        add[rt]+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(add[rt])pushdown(l,r,rt);
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
    pushup(l,r,mid,rt);
}
ll query(int from,int to,int l,int r,int rt){
    if(from<=l&&to>=r){
        return tree[rt]+add[rt]*(r-l+1);
    }
    int mid=(l+r)>>1;
    if(add[rt])pushdown(l,r,rt);
    ll re=0;
    if(from<=mid)re+=query(from,to,lson);
    if(to>mid)re+=query(from,to,rson);
    return re;
}
int main(){
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        build(1,n,1);
        while(q--){
            char s[5];
            int x,y,z;
            scanf("%s",s);
            if(s[0]=='C'){
                scanf("%d%d%d",&x,&y,&z);
                update(x,y,z,1,n,1);
            }else{
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(x,y,1,n,1));
            }
        }
    }
    return 0;
}

