
#include<cstdio>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int tree[400010];
int bj[400010];
void pushup(int rt){
    bj[rt]=0;
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int l,int r,int mid,int rt){
    bj[rt<<1]=bj[rt<<1|1]=bj[rt];
    tree[rt<<1]=(mid-l+1)*bj[rt];
    tree[rt<<1|1]=(r-mid)*bj[rt];
    bj[rt]=0;
}
void build(int l,int r,int rt){
    if(l==r){
        bj[rt]=0;
        tree[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int from,int to,int v,int l,int r,int rt){
    if(from<=l&&to>=r){
        bj[rt]=v;
        tree[rt]=(r-l+1)*v;
        return;
    }
    int mid=(l+r)>>1;
    if(bj[rt])pushdown(l,r,mid,rt);
    if(from<=mid)update(from,to,v,lson);
    if(to>mid)update(from,to,v,rson);
    pushup(rt);
}
int main(){
    int t,n,q;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&q);
        build(1,n,1);
        while(q--){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            update(x,y,z,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",z,tree[1]);
    }
    return 0;
}

